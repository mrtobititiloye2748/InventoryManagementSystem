#include <stdio.h>
#include <string.h>
#include "search.h"

// Searches for items containing the search term
// Uses strstr() to check if term appears inside name or category
int searchItems(InventoryItem* list, int count, const char* term) {

    printf("\n--- Search Results ---\n");
    int found = 0;

    for (int i = 0; i < count; i++) {

        if (strstr(list[i].name, term) || strstr(list[i].category, term)) {

            printf("%d) %s | Qty: %d | $%.2f | Cat: %s | Code: %s\n",
                i,
                list[i].name,
                list[i].quantity,
                list[i].price,
                list[i].category,
                list[i].restockCode);

            found++;
        }
    }

    if (!found) {
        printf("No items found.\n");
    }

    return found;
}
