/**
 * @file fileio.c
 * @brief Implements saving and loading of inventory data to and from files.
 *
 * This module provides persistent storage for the inventory system.
 * It allows writing the current inventory list to a text file and
 * loading previously saved data back into dynamically allocated memory.
 */

#define _CRT_SECURE_NO_WARNINGS
 // ^ Allows use of secure CRT functions without warnings.

#include <stdio.h>
#include <stdlib.h>
#include "fileio.h"

/**
 * @brief Saves the inventory list to a file.
 *
 * Opens the specified file in write mode and outputs each InventoryItem
 * in a space‑separated format:
 *
 *     name quantity price restockCode
 *
 * The file is overwritten if it already exists.
 *
 * @param filename Name of the file to write to.
 * @param list Pointer to the array of inventory items.
 * @param count Number of items in the list.
 */
void saveToFile(const char* filename, InventoryItem* list, int count) {
    FILE* fp = fopen(filename, "w");

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

/**
 * @brief Internal helper declaration required by Microsoft CRT for fscanf_s.
 *
 * @note This is NOT used directly by your code. It exists only because
 *       Visual Studio's secure CRT requires buffer sizes for %s inputs.
 */
int fscanf_s(FILE* fp, char* str, char* text, unsigned size, int* quantity, float* price,
    char* string, unsigned size1);

/**
 * @brief Loads inventory data from a file.
 *
 * Opens the specified file in read mode and loads each item into a temporary
 * InventoryItem structure. Memory is dynamically expanded using realloc
 * as items are read.
 *
 * Expected file format (space‑separated):
 *
 *     name quantity price restockCode
 *
 * Secure input rules:
 * - fscanf_s requires buffer sizes for all %s fields.
 *
 * @param filename Name of the file to read from.
 * @param list Pointer to the dynamic array of InventoryItem pointers.
 * @param count Pointer to the number of items loaded.
 */
void loadFromFile(const char* filename, InventoryItem** list, int* count) {
    FILE* fp = fopen(filename, "r");

    if (!fp) {
        printf("Error opening file.\n");
        return;
    }

    *count = 0;
    *list = NULL;

    InventoryItem temp;

    // Read each item from the file using secure fscanf_s
    while (fscanf_s(fp,
        "%49s %d %f %9s",
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
