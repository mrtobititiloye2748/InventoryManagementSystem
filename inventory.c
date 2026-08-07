#define _CRT_SECURE_NO_WARNINGS
// ^ This disables Microsoft's "unsafe function" warnings.
//   We still use scanf_s (safe version), but this prevents spam warnings.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory.h"
#include "codegen.h"

// addItem()
// Adds a new item to the inventory.
void addItem(InventoryItem** list, int* count) {

    // Expand the dynamic array to fit one more item.
    *list = realloc(*list, (*count + 1) * sizeof(InventoryItem));

    printf("Enter item name: ");

    // FIX: scanf_s requires buffer size for %s inputs.
    // %49s = read up to 49 characters + null terminator.
    // Argument 2 = buffer
    // Argument 3 = buffer size (REQUIRED by Microsoft secure CRT)
    scanf_s("%49s",
        (*list)[*count].name,
        (unsigned)sizeof((*list)[*count].name));

    printf("Enter quantity: ");

    // For integers, scanf_s does NOT require a buffer size.
    scanf_s("%d", &(*list)[*count].quantity);

    printf("Enter price: ");

    // Same rule: doubles do NOT require buffer size.
    scanf_s("%f", &(*list)[*count].price);

    // Generate a restock code and store it.
    strcpy((*list)[*count].restockCode, generateRestockCode());

    (*count)++; // Increase item count.

    printf("Item added successfully!\n");
}

// updateItem()
// Updates an existing item.
void updateItem(InventoryItem* list, int count) {
    char name[50];

    printf("Enter item name to update: ");

    // FIX: buffer size required for %s
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

// removeItem()
// Removes an item from the inventory.
void removeItem(InventoryItem* list, int* count) {
    char name[50];

    printf("Enter item name to remove: ");

    // FIX: buffer size required for %s
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

// listItems()
// Prints all items.
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
