// main.c — ENTRY POINT OF THE PROGRAM
// If this file is missing or wrong, Visual Studio throws "unresolved external symbol main".

#include <stdio.h>
#include <stdlib.h>
#include "ui.h"   // UI controller handles menu + user input

int main() {
    // Pointer to dynamic inventory list
    InventoryItem* list = NULL;

    // Number of items currently stored
    int count = 0;

    // Start the menu loop
    handleUserInput(&list, &count);

    // Free memory before exiting
    free(list);

    return 0; // Successful exit
}
