/**
 * @file main.c
 * @brief Entry point of the Inventory Management System.
 *
 * This file initializes the inventory list, starts the main UI loop,
 * and frees allocated memory before exiting. If this file is missing
 * or incorrectly implemented, the program will fail to link due to
 * the absence of the required `main()` function.
 */

#include <stdio.h>
#include <stdlib.h>
#include "ui.h"   /**< UI controller handles menu + user input */

 /**
  * @brief Program entry point.
  *
  * This function:
  * - Initializes the dynamic inventory list
  * - Sets the initial item count to zero
  * - Calls handleUserInput() to start the main menu loop
  * - Frees dynamically allocated memory before exiting
  *
  * @return int Returns 0 on successful program termination.
  */
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
/**
 * @file main.c
 * @brief Entry point of the Inventory Management System.
 *
 * This file initializes the inventory list, starts the main UI loop,
 * and frees allocated memory before exiting. If this file is missing
 * or incorrectly implemented, the program will fail to link due to
 * the absence of the required `main()` function.
 */

#include <stdio.h>
#include <stdlib.h>
#include "ui.h"   /**< UI controller handles menu + user input */

 /**
  * @brief Program entry point.
  *
  * This function:
  * - Initializes the dynamic inventory list
  * - Sets the initial item count to zero
  * - Calls handleUserInput() to start the main menu loop
  * - Frees dynamically allocated memory before exiting
  *
  * @return int Returns 0 on successful program termination.
  */
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
