/**
 * @file inventory.h
 * @brief Inventory module for managing items in the system.
 *
 * This module defines the InventoryItem structure and provides
 * functions for adding, updating, removing, and listing items.
 * It is one of the core modules used during integration.
 */

#ifndef INVENTORY_H
#define INVENTORY_H

 /**
  * @def CODE_LEN
  * @brief Length of the restock code (10 characters + null terminator).
  */
#define CODE_LEN 10

  /**
   * @struct InventoryItem
   * @brief Represents a single inventory item in the system.
   *
   * Each item contains:
   * - name: item name
   * - quantity: number of units available
   * - price: cost per unit
   * - category: item category (e.g., food, tools)
   * - restockCode: randomly generated alphanumeric code for reordering
   */
typedef struct {
    char name[50];                 /**< Item name */
    int quantity;                  /**< Number of units */
    float price;                   /**< Price per unit */
    char category[30];             /**< Item category */
    char restockCode[CODE_LEN + 1];/**< Randomly generated restock code */
} InventoryItem;

/**
 * @brief Adds a new item to the inventory list.
 *
 * Allocates memory (if needed), prompts the user for item details,
 * generates a restock code, and appends the item to the list.
 *
 * @param list Pointer to the dynamic array of InventoryItem pointers.
 * @param count Pointer to the number of items currently stored.
 */
void addItem(InventoryItem** list, int* count);

/**
 * @brief Updates an existing inventory item.
 *
 * Searches for an item by name and allows the user to modify
 * its quantity and price.
 *
 * @param list Array of inventory items.
 * @param count Number of items in the list.
 */
void updateItem(InventoryItem* list, int count);

/**
 * @brief Removes an item from the inventory list.
 *
 * Searches for an item by name, deletes it, and shifts the
 * remaining items left to maintain array continuity.
 *
 * @param list Array of inventory items.
 * @param count Pointer to the number of items in the list.
 */
void removeItem(InventoryItem* list, int* count);

/**
 * @brief Prints all inventory items.
 *
 * Displays each item's name, quantity, price, category,
 * and restock code.
 *
 * @param list Array of inventory items.
 * @param count Number of items in the list.
 */
void listItems(InventoryItem* list, int count);

#endif
