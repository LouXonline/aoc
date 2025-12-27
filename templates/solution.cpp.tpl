#include <iostream>
#include <string>
#include "aoc_utils.hpp"

#define STR(x) #x
#define XSTR(x) STR(x)

// --- Solver ---
int solve(const std::string &data) {
    // Implement your solution here
    // Return an integer result
    return 0;
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
    std::cout << "Result: " << result << std::endl;

    return 0;
}
