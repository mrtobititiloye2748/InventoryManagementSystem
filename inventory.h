#ifndef INVENTORY_H
#define INVENTORY_H

// Length of the restock code (10 characters + null terminator)
#define CODE_LEN 10

// Structure representing ONE inventory item.
// Every item has:
// - name: item name
// - quantity: how many units
// - price: cost per unit
// - category: item category (e.g., food, tools)
// - restockCode: randomly generated code for reordering
typedef struct {
    char name[50];
    int quantity;
    float price;
    char category[30];
    char restockCode[CODE_LEN + 1];
} InventoryItem;

// Adds a new item to the inventory list
void addItem(InventoryItem** list, int* count);

// Updates an existing item (quantity, price)
void updateItem(InventoryItem* list, int count);

// Removes an item from the list
void removeItem(InventoryItem* list, int* count);

// Prints all items in the inventory
void listItems(InventoryItem* list, int count);

#endif
