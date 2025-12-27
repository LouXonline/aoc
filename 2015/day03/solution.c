#include <stdio.h>
#include <stdlib.h>

#include "aoc_utils.h"

#define STR(x) #x
#define XSTR(x) STR(x)

// --- Solver ---
int solve_part_one(const char *data) {
    int x = 0, y = 0;
    int visited[1000][1000] = {0};
    visited[500][500] = 1; // Starting position

    for (const char *p = data; *p; p++) {
        switch (*p) {
            case '^': y++; break;
            case 'v': y--; break;
            case '>': x++; break;
            case '<': x--; break;
        }
        visited[x + 500][y + 500] = 1;
    }

    int count = 0;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            if (visited[i][j]) {
                count++;
            }
        }
    }
    return count;
}

int solve_part_two(const char *data) {
    int x[2] = {0, 0}, y[2] = {0, 0};
    int visited[1000][1000] = {0};
    visited[500][500] = 1; // Starting position

    for (const char *p = data; *p; p++) {
        int idx = (p - data) % 2; // Alternate between Santa and Robo-Santa
        switch (*p) {
            case '^': y[idx]++; break;
            case 'v': y[idx]--; break;
            case '>': x[idx]++; break;
            case '<': x[idx]--; break;
        }
        visited[x[idx] + 500][y[idx] + 500] = 1;
    }

    int count = 0;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            if (visited[i][j]) {
                count++;
            }
        }
    }
    return count;
}

// --- Main ---
int main(void) {
    const char *path = XSTR(AOC_DATA_DIR) "/input.txt";
    char *data = aoc_read_file(path);
    if (!data) {
        perror(path);
        return 1;
    }

    int result = solve_part_one(data);
    printf("Part One: %d\n", result);

    result = solve_part_two(data);
    printf("Part Two: %d\n", result);

    free(data);

    return 0;
}
