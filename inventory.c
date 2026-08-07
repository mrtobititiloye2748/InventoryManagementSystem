/**
 * @file inventory.c
 * @brief Implements inventory management operations such as adding,
 * updating, removing, and listing items.
 *
 * This module works with dynamically allocated arrays of InventoryItem
 * and integrates with the CodeGen module to generate restock codes.
 */

#define _CRT_SECURE_NO_WARNINGS
 // ^ Disables Microsoft's "unsafe function" warnings for scanf.
 //   scanf_s is used for secure input handling.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory.h"
#include "codegen.h"

/**
 * @brief Adds a new item to the inventory.
 *
 * This function expands the dynamic inventory array using realloc,
 * prompts the user for item details, generates a restock code,
 * and stores the new item in the list.
 *
 * @param list Pointer to the dynamic array of InventoryItem pointers.
 * @param count Pointer to the number of items currently stored.
 */
void addItem(InventoryItem** list, int* count) {

    // Expand the dynamic array to fit one more item.
    *list = realloc(*list, (*count + 1) * sizeof(InventoryItem));

    printf("Enter item name: ");

    // Secure input: scanf_s requires buffer size for %s inputs.
    scanf_s("%49s",
        (*list)[*count].name,
        (unsigned)sizeof((*list)[*count].name));

    printf("Enter quantity: ");
    scanf_s("%d", &(*list)[*count].quantity);

    printf("Enter price: ");
    scanf_s("%f", &(*list)[*count].price);

    // Generate a restock code and store it.
    strcpy((*list)[*count].restockCode, generateRestockCode());

    (*count)++; // Increase item count.

    printf("Item added successfully!\n");
}

/**
 * @brief Updates an existing inventory item.
 *
 * Searches for an item by name and allows the user to modify
 * its quantity and price. If the item is not found, an error
 * message is displayed.
 *
 * @param list Array of inventory items.
 * @param count Number of items in the list.
 */
void updateItem(InventoryItem* list, int count) {
    char name[50];

    printf("Enter item name to update: ");

    // Secure input for item name
    scanf_s("%49s",
        name,
        (unsigned)sizeof(name));

    // Search for the item
    for (int i = 0; i < count; i++) {
        if (strcmp(list[i].name, name) == 0) {

            printf("New quantity: ");
            scanf_s("%d", &list[i].quantity);

            printf("New price: ");
            scanf_s("%f", &list[i].price);

            printf("Item updated!\n");
            return;
        }
    }

    printf("Item not found.\n");
}

/**
 * @brief Removes an item from the inventory.
 *
 * Searches for an item by name, deletes it, and shifts the remaining
 * items left to maintain array continuity. If the item is not found,
 * an error message is displayed.
 *
 * @param list Array of inventory items.
 * @param count Pointer to the number of items in the list.
 */
void removeItem(InventoryItem* list, int* count) {
    char name[50];

    printf("Enter item name to remove: ");

    // Secure input for item name
    scanf_s("%49s",
        name,
        (unsigned)sizeof(name));

    // Search for the item
    for (int i = 0; i < *count; i++) {
        if (strcmp(list[i].name, name) == 0) {

            // Shift items left to overwrite the removed item.
            for (int j = i; j < *count - 1; j++) {
                list[j] = list[j + 1];
            }

            (*count)--;

            printf("Item removed!\n");
            return;
        }
    }

    printf("Item not found.\n");
}

/**
 * @brief Prints all inventory items.
 *
 * Displays each item's name, quantity, price, and restock code.
 *
 * @param list Array of inventory items.
 * @param count Number of items in the list.
 */
void listItems(InventoryItem* list, int count) {
    printf("\n--- Inventory List ---\n");

    for (int i = 0; i < count; i++) {
        printf("%s | Qty: %d | Price: %.2f | Code: %s\n",
            list[i].name,
            list[i].quantity,
            list[i].price,
            list[i].restockCode);
    }
}
