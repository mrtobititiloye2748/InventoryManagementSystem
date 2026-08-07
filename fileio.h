/**
 * @file fileio.h
 * @brief Declares functions for saving and loading inventory data from files.
 *
 * This module handles persistent storage for the inventory system.
 * It allows saving the current inventory list to a text file and
 * loading previously saved data back into dynamically allocated memory.
 */

#ifndef FILEIO_H
#define FILEIO_H

#include "inventory.h"

 /**
  * @brief Saves the inventory list to a file.
  *
  * Writes each InventoryItem to a text file in a consistent format.
  * The function does not modify the inventory list; it only outputs data.
  *
  * @param filename Name of the file to write to.
  * @param list Pointer to the array of inventory items.
  * @param count Number of items in the list.
  *
  * @note The file is overwritten if it already exists.
  */
void saveToFile(const char* filename, InventoryItem* list, int count);

/**
 * @brief Loads inventory data from a file.
 *
 * Reads inventory items from a text file and stores them in a dynamically
 * allocated array. The function reallocates memory as needed and updates
 * the item count.
 *
 * @param filename Name of the file to read from.
 * @param list Pointer to the dynamic array of InventoryItem pointers.
 * @param count Pointer to the number of items loaded.
 *
 * @note If the file does not exist or cannot be opened, the function
 *       prints an error message and leaves the list unchanged.
 */
void loadFromFile(const char* filename, InventoryItem** list, int* count);

#endif
