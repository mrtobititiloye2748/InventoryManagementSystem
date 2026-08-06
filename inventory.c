#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory.h"
#include "codegen.h"   // for generateRestockCode()

// Adds a new item to the inventory list
// Steps:
// 1. Expand the list using realloc()
// 2. Ask user for item details
// 3. Generate a random restock code
// 4. Increase item count
void addItem(InventoryItem** list, int* count) {

    // Expand list by 1 item
    *list = realloc(*list, (*count + 1) * sizeof(InventoryItem));
    InventoryItem* item = &(*list)[*count];

    printf("Enter item name: ");
    scanf_s("%49s", item->name);

    printf("Enter quantity: ");
    scanf_s("%d", &item->quantity);

    printf("Enter price: ");
    scanf_s("%f", &item->price);

    printf("Enter category: ");
    scanf_s("%29s", item->category);

    // Generate random restock code
    generateRestockCode(item->restockCode, CODE_LEN);

    (*count)++;
}

// Updates an existing item
// User chooses item by index
void updateItem(InventoryItem* list, int count) {
    int index;

    printf("Enter item index to update: ");
    scanf_s("%d", &index);

    if (index < 0 || index >= count) {
        printf("Invalid index.\n");
        return;
    }

    printf("New quantity: ");
    scanf_s("%d", &list[index].quantity);

    printf("New price: ");
    scanf_s("%f", &list[index].price);
}

// Removes an item from the list
// Steps:
// 1. Ask for index
// 2. Shift items left
// 3. Reduce count
void removeItem(InventoryItem* list, int* count) {
    int index;

    printf("Enter item index to remove: ");
    scanf_s("%d", &index);

    if (index < 0 || index >= *count) {
        printf("Invalid index.\n");
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        list[i] = list[i + 1];
    }

    (*count)--;
}

// Prints all items
void listItems(InventoryItem* list, int count) {
    printf("\n--- Inventory List ---\n");

    for (int i = 0; i < count; i++) {
        printf("%d) %s | Qty: %d | $%.2f | Cat: %s | Code: %s\n",
            i,
            list[i].name,
            list[i].quantity,
            list[i].price,
            list[i].category,
            list[i].restockCode);
    }
}
