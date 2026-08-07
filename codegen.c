/**
 * @file codegen.c
 * @brief Defines the function responsible for generating restock codes.
 *
 * This module implements generateRestockCode(), which creates a random
 * alphanumeric restock code used by the Inventory module. The function
 * returns a pointer to a static buffer, allowing the caller to store
 * the generated code without needing to manage dynamic memory.
 */

#include "codegen.h"   /**< Must match the header declaration */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 /**
  * @brief Generates a random alphanumeric restock code.
  *
  * This function creates a restock code in the format:
  *     RSK####
  * where #### is a zero‑padded 4‑digit random number (0000–9999).
  *
  * The function uses a static character array so the memory remains
  * valid after returning. Each call overwrites the previous code.
  *
  * @return char* Pointer to a static character array containing the code.
  *
  * @note The caller should copy the returned string if long‑term storage
  *       is required, because subsequent calls will overwrite the buffer.
  */
char* generateRestockCode() {
    static char code[10];  // static so memory stays valid after return

    // Seed the random number generator
    srand((unsigned int)time(NULL));

    // Create a 4-digit random number and store it in the code array
    snprintf(code, sizeof(code), "RSK%04d", rand() % 10000);

    return code;  // Return pointer to static array
}
