#include <iostream>
#include <string>
#include "aoc_utils.hpp"

#define STR(x) #x
#define XSTR(x) STR(x)

// --- Solver ---
int solve_part_one(const std::string &data) {
    int x = 0, y = 0;
    bool visited[1000][1000] = {false};
    visited[500][500] = true; // Starting position

    for (char ch : data) {
        switch (ch) {
            case '^': y++; break;
            case 'v': y--; break;
            case '>': x++; break;
            case '<': x--; break;
        }
        visited[x + 500][y + 500] = true;
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

int solve_part_two(const std::string &data) {
    int x[2] = {0, 0}, y[2] = {0, 0};
    bool visited[1000][1000] = {false};
    visited[500][500] = true; // Starting position

    for (size_t i = 0; i < data.size(); ++i) {
        int idx = i % 2; // Alternate between Santa and Robo-Santa
        char ch = data[i];
        switch (ch) {
            case '^': y[idx]++; break;
            case 'v': y[idx]--; break;
            case '>': x[idx]++; break;
            case '<': x[idx]--; break;
        }
        visited[x[idx] + 500][y[idx] + 500] = true;
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
int main() {
    std::string path = std::string(XSTR(AOC_DATA_DIR)) + "/input.txt";
    std::string data = aoc::read_file(path);
    if (data.empty()) {
        std::cerr << "Failed to read " << path << std::endl;
        return 1;
    }

    int result = solve_part_one(data);
    std::cout << "Part One: " << result << std::endl;

    result = solve_part_two(data);
    std::cout << "Part Two: " << result << std::endl;

    return 0;
}
