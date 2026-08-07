/**
 * @file search.c
 * @brief Implements substring‑based search for inventory items.
 *
 * This module provides functionality to search inventory items
 * by checking whether a user‑provided term appears inside either
 * the item name or category. Matching items are printed to the console.
 */

#include <stdio.h>
#include <string.h>
#include "search.h"

 /**
  * @brief Searches for inventory items containing the given term.
  *
  * This function performs a case‑sensitive substring search using `strstr()`
  * on both the `name` and `category` fields of each InventoryItem.
  * Any item whose name or category contains the search term is printed.
  *
  * Example:
  * - term = "tool" will match items with category "tools"
  * - term = "app" will match items with name "apple"
  *
  * @param list Pointer to the array of inventory items.
  * @param count Number of items in the list.
  * @param term Substring to search for (case‑sensitive).
  * @return int Number of items found that match the search term.
  *
  * @note The function prints results directly and does not modify the list.
  */
int searchItems(InventoryItem* list, int count, const char* term) {

    printf("\n--- Search Results ---\n");
    int found = 0;

    for (int i = 0; i < count; i++) {

        // Match if term appears in name OR category
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
