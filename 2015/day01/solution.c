#include <stdio.h>
#include <stdlib.h>

#include "aoc_utils.h"

#define STR(x) #x
#define XSTR(x) STR(x)

int solve_part_one(const char *data) {
    int floor = 0;

    for (const char *ptr = data; *ptr != '\0'; ptr++) {
        if (*ptr == '(') {
            floor++;
        } else if (*ptr == ')') {
            floor--;
        }
    }
    return floor;
}

int main(void) {
    const char *path = XSTR(AOC_DATA_DIR) "/input.txt";
    char *data = aoc_read_file(path);
    if (!data) {
        perror("No data input");
        return 1;
    }

    int floor = solve_part_one(data);

    free(data);

    printf("Final floor: %d\n", floor);
    return 0;
}