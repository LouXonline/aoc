#include <iostream>
#include <string>
#include "aoc_utils.hpp"

#define STR(x) #x
#define XSTR(x) STR(x)

// --- Solver function ---
int solve_part_one(const std::string &data) {
    int floor = 0;

    for (char c : data) {
        if (c == '(') floor++;
        else if (c == ')') floor--;
    }
    return floor;
}

int solve_part_two(const std::string &data) {
    int floor = 0;

    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i] == '(') floor++;
        else if (data[i] == ')') floor--;

        if (floor == -1) {
            return i + 1; // 1-based index
        }
    }
    return -1; // Not found
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
    std::cout << "Final floor: " << result << std::endl;

    int position = solve_part_two(data);
    if (position != -1) {
        std::cout << "Position of first basement entry: " << position << std::endl;
    } else {
        std::cout << "Basement entry not found." << std::endl;
    }

    return 0;
}
