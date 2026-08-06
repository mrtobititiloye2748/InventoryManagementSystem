#include <stdio.h>
#include <stdlib.h>
#include "ui.h"

// Main function
// This is the entry point of the entire program
// It creates the inventory list and passes it to the UI controller
int main() {

    InventoryItem* list = NULL; // dynamic array of inventory items
    int count = 0;              // number of items currently stored

    // Start the user interface loop
    handleUserInput(&list, &count);

    // Free dynamically allocated memory before exiting
    free(list);

    return 0;
}
