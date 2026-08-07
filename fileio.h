#ifndef FILEIO_H
#define FILEIO_H

#include "inventory.h"

// Saves inventory to a file
void saveToFile(const char *filename, InventoryItem *list, int count);

// Loads inventory from a file
void loadFromFile(const char *filename, InventoryItem **list, int *count);

#endif