/**
 * @file codegen.h
 * @brief Declares the restock code generator function.
 *
 * This module provides the interface for generating a random
 * alphanumeric restock code used by the Inventory module.
 *
 * IMPORTANT:
 * The declaration here MUST match the definition in codegen.c.
 * If they differ, linker errors will occur.
 */

#ifndef CODEGEN_H
#define CODEGEN_H

 /**
  * @brief Generates a random alphanumeric restock code.
  *
  * The function returns a pointer to a static character array
  * containing a newly generated restock code. The code length
  * is defined by CODE_LEN in inventory.h (10 characters + null terminator).
  *
  * @return char* Pointer to a static string containing the restock code.
  *
  * @note Because the returned buffer is static, its contents will be
  * overwritten on each call. If persistent storage is required,
  * copy the returned string into another buffer.
  */
char* generateRestockCode();

#endif
