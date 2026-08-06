#include <stdio.h>
#include <stdlib.h>
#include "ui.h"

// Main function
// Creates the inventory list and starts the UI
int main() {

    InventoryItem* list = NULL; // dynamic list
    int count = 0;              // number of items

    handleUserInput(&list, &count);

    free(list); // free memory before exiting
    return 0;
}
