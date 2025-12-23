#include <iostream>
#include <string>
#include "aoc_utils.hpp"

#define STR(x) #x
#define XSTR(x) STR(x)

// --- Solver function ---
int solve(const std::string &data) {
    int floor = 0;
    for (char c : data) {
        if (c == '(') floor++;
        else if (c == ')') floor--;
    }
    return floor;
}

// --- Main ---
int main() {
    std::string path = std::string(XSTR(AOC_DATA_DIR)) + "/input.txt";

    std::string data = aoc::read_file(path);
    if (data.empty()) {
        std::cerr << "Failed to read " << path << std::endl;
        return 1;
    }

    int result = solve(data);
    std::cout << "Final floor: " << result << std::endl;

    return 0;
}
