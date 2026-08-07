/**
 * @file ui.c
 * @brief Implements the user interface and main menu controller.
 *
 * This module handles all user interaction, including printing the menu,
 * reading user choices, and routing commands to the correct modules
 * (Inventory, Search, FileIO). It acts as the central controller for
 * the entire inventory management system.
 */

#define _CRT_SECURE_NO_WARNINGS
 // ^ Prevents Visual Studio from complaining about "unsafe" functions.
 //   scanf_s is used for secure input handling.

#include <stdio.h>
#include <string.h>
#include "ui.h"
#include "search.h"
#include "fileio.h"

/**
 * @brief Displays the menu options for the inventory system.
 *
 * This function prints all available actions the user can perform:
 * - Add item
 * - Update item
 * - Remove item
 * - List items
 * - Search items
 * - Save inventory to file
 * - Load inventory from file
 * - Exit program
 *
 * It is called at the beginning of each loop iteration in handleUserInput().
 */
void printMenu() {
    printf("\n--- Inventory Menu ---\n");
    printf("1. Add Item\n");
    printf("2. Update Item\n");
    printf("3. Remove Item\n");
    printf("4. List Items\n");
    printf("5. Search Items\n");
    printf("6. Save to File\n");
    printf("7. Load from File\n");
    printf("0. Exit\n");
}

/**
 * @brief Main menu loop and command controller.
 *
 * This function continuously:
 * - Prints the menu
 * - Reads the user's choice
 * - Calls the appropriate module function
 *
 * It handles:
 * - Adding items
 * - Updating items
 * - Removing items
 * - Listing items
 * - Searching items
 * - Saving inventory to a file
 * - Loading inventory from a file
 *
 * The loop continues until the user selects option 0 (Exit).
 *
 * @param list Pointer to the dynamic array of InventoryItem pointers.
 * @param count Pointer to the number of items currently stored.
 */
void handleUserInput(InventoryItem** list, int* count) {
    int choice;
    char term[50];
    char filename[50];

    do {
        printMenu();
        printf("Enter choice: ");

        // Secure integer input
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            addItem(list, count);
            break;

        case 2:
            updateItem(*list, *count);
            break;

        case 3:
            removeItem(*list, count);
            break;

        case 4:
            listItems(*list, *count);
            break;

        case 5:
            printf("Search term: ");

            // Secure string input
            scanf_s("%49s",
                term,
                (unsigned)sizeof(term));

            searchItems(*list, *count, term);
            break;

        case 6:
            printf("Filename: ");

            // Secure string input
            scanf_s("%49s",
                filename,
                (unsigned)sizeof(filename));

            saveToFile(filename, *list, *count);
            break;

        case 7:
            printf("Filename: ");

            // Secure string input
            scanf_s("%49s",
                filename,
                (unsigned)sizeof(filename));

            loadFromFile(filename, list, count);
            break;

        case 0:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice.\n");
        }

    } while (choice != 0);
}
