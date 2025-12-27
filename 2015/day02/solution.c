#include <stdio.h>
#include <stdlib.h>

#include "aoc_utils.h"

#define STR(x) #x
#define XSTR(x) STR(x)

// --- Solver ---
int solve_part_one(const char *data) {
    int total = 0;
    const char *line = data;
    while (*line) {
        int length, width, height;
        if (sscanf(line, "%dx%dx%d", &length, &width, &height) != 3) {
            break; // Malformed line or end of input
        }

        int side1 = length * width;
        int side2 = width * height;
        int side3 = height * length;

        int surface_area = 2 * (side1 + side2 + side3);
        int smallest_side = side1;
        if (side2 < smallest_side) smallest_side = side2;
        if (side3 < smallest_side) smallest_side = side3;

        total += surface_area + smallest_side;

        // Move to the next line
        while (*line && *line != '\n') {
            line++;
        }
        if (*line == '\n') {
            line++;
        }
    }
    return total;
}

int solve_part_two(const char *data) {
    int total = 0;
    const char *line = data;
    while (*line) {
        int length, width, height;
        if (sscanf(line, "%dx%dx%d", &length, &width, &height) != 3) {
            break; // Malformed line or end of input
        }   
        int perim1 = 2 * (length + width);
        int perim2 = 2 * (width + height);
        int perim3 = 2 * (height + length);
        int smallest_perim = perim1;
        if (perim2 < smallest_perim) smallest_perim = perim2;
        if (perim3 < smallest_perim) smallest_perim = perim3;
        int volume = length * width * height;
        total += smallest_perim + volume;
        // Move to the next line
        while (*line && *line != '\n') {
            line++;
        }
        if (*line == '\n') {
            line++;
        }
    }
    return total;
}

// --- Main ---
int main(void) {
    const char *path = XSTR(AOC_DATA_DIR) "/input.txt";
    char *data = aoc_read_file(path);
    if (!data) {
        perror("No data input");
        return 1;
    }

    int part_one_result = solve_part_one(data);
    printf("Part One: %d\n", part_one_result);

    int part_two_result = solve_part_two(data);
    printf("Part Two: %d\n", part_two_result);

    free(data);

    return 0;
}
