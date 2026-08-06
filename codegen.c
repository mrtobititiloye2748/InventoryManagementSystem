// codegen.c — DEFINES generateRestockCode()
// If this file is missing or wrong, Visual Studio throws a linker error.

#include "codegen.h"   // Must match the header declaration
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This function creates a random restock code like "RSK1234"
char* generateRestockCode() {
    static char code[10];  // static so memory stays valid after return

    // Seed the random number generator
    srand((unsigned int)time(NULL));

    // Create a 4-digit random number and store it in the code array
    snprintf(code, sizeof(code), "RSK%04d", rand() % 10000);

    return code;  // Return pointer to static array
}
