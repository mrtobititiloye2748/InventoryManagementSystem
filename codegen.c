#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "codegen.h"

// Generates a random code like: A9F3K2L8QZ
// Steps:
// 1. Seed random generator with time()
// 2. Pick random characters from charset
// 3. Store them in buffer
void generateRestockCode(char *buffer, int length) {

    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    srand(time(NULL)); // seed random generator

    for (int i = 0; i < length; i++) {
        buffer[i] = charset[rand() % (sizeof(charset) - 1)];
    }

    buffer[length] = '\0'; // null terminate
}
