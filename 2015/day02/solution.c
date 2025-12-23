#include <stdio.h>
#include <stdlib.h>

#include "aoc_utils.h"

#define STR(x) #x
#define XSTR(x) STR(x)

// --- Solver ---
int solve(const char *data) {
    // add content
    return 0;  // placeholder
}

// --- Main ---
int main(void) {
    const char *path = XSTR(AOC_DATA_DIR) "/input.txt";

    char *data = aoc_read_file(path);
    if (!data) {
        perror(path);
        return 1;
    }

    int result = solve(data);
    free(data);

    printf("Result: %d\n", result);
    return 0;
}
