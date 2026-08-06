#include <stdio.h>
#include <string.h>
#include "ui.h"
#include "search.h"
#include "fileio.h"

// Prints the main menu options
// This is shown every time the user needs to choose an action
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

// Handles user input and calls the correct module functions
// This function loops until the user chooses 0 (Exit)
void handleUserInput(InventoryItem** list, int* count) {

    int choice;
    char term[50];
    char filename[50];

    do {
        printMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);

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
            scanf("%49s", term);
            searchItems(*list, *count, term);
            break;

        case 6:
            printf("Filename: ");
            scanf("%49s", filename);
            saveToFile(filename, *list, *count);
            break;

        case 7:
            printf("Filename: ");
            scanf("%49s", filename);
            loadFromFile(filename, list, count);
            break;

        case 0:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice. Try again.\n");
        }

    } while (choice != 0);
}
