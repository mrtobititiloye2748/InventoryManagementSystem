#define _CRT_SECURE_NO_WARNINGS
// ^ Allows use of secure CRT functions without warnings.

#include <stdio.h>
#include <stdlib.h>
#include "fileio.h"

// saveToFile()
// Writes inventory to a file.
void saveToFile(const char *filename, InventoryItem *list, int count) {
    FILE *fp = fopen(filename, "w");

    if (!fp) {
        printf("Error opening file.\n");
        return;
    }

    // Write each item to the file.
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s %d %.2f %s\n",
                list[i].name,
                list[i].quantity,
                list[i].price,
                list[i].restockCode);
    }

    fclose(fp);
    printf("Saved!\n");
}

int fscanf_s(FILE * fp, char * str, char * text, unsigned size, int * quantity, float * price,
             char * string, unsigned size1);

// loadFromFile()
// Reads inventory from a file.
void loadFromFile(const char *filename, InventoryItem **list, int *count) {
    FILE *fp = fopen(filename, "r");

    if (!fp) {
        printf("Error opening file.\n");
        return;
    }

    *count = 0;
    *list = NULL;

    InventoryItem temp;

    // FIX: fscanf_s requires buffer sizes for %s inputs.
    // The format string reads:
    // - name (string)
    // - quantity (int)
    // - price (double)
    // - restockCode (string)
    while (fscanf_s(fp,
                    "%49s %d %lf %9s",
                    temp.name, (unsigned)sizeof(temp.name), // REQUIRED size
                    &temp.quantity,
                    &temp.price,
                    temp.restockCode, (unsigned)sizeof(temp.restockCode)) == 4) {

        // Expand list and store item
        *list = realloc(*list, (*count + 1) * sizeof(InventoryItem));
        (*list)[*count] = temp;
        (*count)++;
                    }

    fclose(fp);
    printf("Loaded!\n");
}
