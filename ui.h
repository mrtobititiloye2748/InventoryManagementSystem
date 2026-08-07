/**
 * @file ui.h
 * @brief Declares user interface functions for the inventory system.
 *
 * This module handles all user‑facing interaction, including printing
 * the main menu and routing user commands to the correct module.
 * It acts as the controller for the entire program.
 */

#ifndef UI_H
#define UI_H

#include "inventory.h"

 /**
  * @brief Prints the menu options for the inventory system.
  *
  * This function displays all available actions the user can perform,
  * such as adding, updating, removing, listing, searching, saving,
  * and loading inventory items.
  *
  * It is called at the beginning of each loop iteration inside
  * handleUserInput().
  */
void printMenu();

/**
 * @brief Handles user input and routes commands to the correct module.
 *
 * This function acts as the main controller of the program. It:
 * - Reads the user's menu choice
 * - Calls the appropriate module function (Inventory, Search, FileIO)
 * - Continues looping until the user chooses to exit
 *
 * @param list Pointer to the dynamic array of InventoryItem pointers.
 * @param count Pointer to the number of items currently stored.
 *
 * @note This function is responsible for the main program flow.
 */
void handleUserInput(InventoryItem** list, int* count);

#endif
