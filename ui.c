#define _CRT_SECURE_NO_WARNINGS
// ^ Prevents Visual Studio from complaining about "unsafe" functions.
//   We still use scanf_s, which is safe.

#include <stdio.h>
#include <string.h>
#include "ui.h"
#include "search.h"
#include "fileio.h"

// printMenu()
// Displays the menu options.
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

// handleUserInput()
// Main menu loop.
void handleUserInput(InventoryItem** list, int* count) {
    int choice;
    char term[50];
    char filename[50];

    do {
        printMenu();
        printf("Enter choice: ");

        // FIX: scanf → scanf_s
        // For integers, no buffer size is needed.
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

            // FIX: buffer size required for %s
            scanf_s("%49s",
                term,
                (unsigned)sizeof(term));

            searchItems(*list, *count, term);
            break;

        case 6:
            printf("Filename: ");

            // FIX: buffer size required for %s
            scanf_s("%49s",
                filename,
                (unsigned)sizeof(filename));

            saveToFile(filename, *list, *count);
            break;

        case 7:
            printf("Filename: ");

            // FIX: buffer size required for %s
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
