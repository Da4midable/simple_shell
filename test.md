#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main() {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    printf("Enter a line of text (or press Enter to exit):\n");

    // Read a line of input
    read = getline(&line, &len, stdin);

    if (read != -1) {
        // Print the line
        printf("You entered: %s", line);
    } else {
        printf("Error reading input.\n");
    }

    // Free the allocated memory
    free(line);

    return 0;
}
