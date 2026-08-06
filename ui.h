#ifndef UI_H
#define UI_H

#include "inventory.h"

// Prints the menu options for the inventory system
// Called every loop iteration in handleUserInput()
void printMenu();

// Handles user input and routes commands to the correct module
// This function is the "controller" of the entire program
void handleUserInput(InventoryItem** list, int* count);

#endif
