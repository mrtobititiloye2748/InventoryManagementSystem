#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileio.h"

// Saves inventory to a file in this format:
// name;quantity;price;category;restockCode
int saveToFile(const char *filename, InventoryItem *list, int count) {

    FILE *fp = fopen(filename, "w");
    if (!fp) return 0;

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s;%d;%.2f;%s;%s\n",
                list[i].name,
                list[i].quantity,
                list[i].price,
                list[i].category,
                list[i].restockCode);
    }

    fclose(fp);
    return 1;
}

// Loads inventory from a file
// Steps:
// 1. Read each line
// 2. Parse fields using sscanf()
// 3. Expand list using realloc()
// 4. Store values in InventoryItem
int loadFromFile(const char *filename, InventoryItem **list, int *count) {

    FILE *fp = fopen(filename, "r");
    if (!fp) return 0;

    char line[256];
    *count = 0;

    while (fgets(line, sizeof(line), fp)) {

        *list = realloc(*list, (*count + 1) * sizeof(InventoryItem));
        InventoryItem *item = &(*list)[*count];

        sscanf(line, "%49[^;];%d;%f;%29[^;];%10s",
               item->name,
               &item->quantity,
               &item->price,
               item->category,
               item->restockCode);

        (*count)++;
    }

    fclose(fp);
    return 1;
}
