/**
 * @file search.h
 * @brief Declares the search functionality for inventory items.
 *
 * This module provides a function that searches the inventory list
 * by matching a user‑provided term against item names or categories.
 * It is used by the main program to allow quick lookup of items.
 */

#ifndef SEARCH_H
#define SEARCH_H

#include "inventory.h"

 /**
  * @brief Searches inventory items by name or category.
  *
  * This function compares the search term with both the `name`
  * and `category` fields of each InventoryItem. Any item that
  * contains the term (case‑sensitive substring match) is considered
  * a match and will be displayed by the caller.
  *
  * @param list Pointer to the array of inventory items.
  * @param count Number of items in the list.
  * @param term The search term (substring) to match.
  * @return int Number of items found that match the search term.
  *
  * @note The function does not modify the inventory list. It only
  *       performs comparisons and returns the number of matches.
  */
int searchItems(InventoryItem* list, int count, const char* term);

#endif
