#ifndef SEARCH_H
#define SEARCH_H

#include "inventory.h"

// Searches items by name or category
int searchItems(InventoryItem* list, int count, const char* term);

#endif
