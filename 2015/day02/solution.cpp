#include <iostream>
#include <string>
#include "aoc_utils.hpp"

#define STR(x) #x
#define XSTR(x) STR(x)

// --- Solver ---
int solve_part_one(const std::string &data) {
    int total = 0;
    size_t start = 0;
    while (start < data.size()) {
        size_t end = data.find('\n', start);
        if (end == std::string::npos) {
            end = data.size();
        }
        std::string line = data.substr(start, end - start);
        int length, width, height;
        if (sscanf(line.c_str(), "%dx%dx%d", &length, &width, &height) != 3) {
            break; // Malformed line or end of input
        }
        int side1 = length * width;
        int side2 = width * height;
        int side3 = height * length;    
        int surface_area = 2 * (side1 + side2 + side3);
        int smallest_side = std::min({side1, side2, side3});
        total += surface_area + smallest_side;
        start = end + 1;
    }
    return total;
}

int solve_part_two(const std::string &data) {
    int total = 0;
    size_t start = 0;
    while (start < data.size()) {
        size_t end = data.find('\n', start);
        if (end == std::string::npos) {
            end = data.size();
        }
        std::string line = data.substr(start, end - start);
        int length, width, height;
        if (sscanf(line.c_str(), "%dx%dx%d", &length, &width, &height) != 3) {
            break; // Malformed line or end of input
        }   
        int perim1 = 2 * (length + width);
        int perim2 = 2 * (width + height);
        int perim3 = 2 * (height + length);
        int smallest_perim = std::min({perim1, perim2, perim3});
        int volume = length * width * height;
        total += smallest_perim + volume;
        start = end + 1;
    }
    return total;
}

// --- Main ---
int main() {
    std::string path = std::string(XSTR(AOC_DATA_DIR)) + "/input.txt";
    std::string data = aoc::read_file(path);
    if (data.empty()) {
        std::cerr << "Failed to read " << path << std::endl;
        return 1;
    }

    int part_one_result = solve_part_one(data);
    std::cout << "Part One Result: " << part_one_result << std::endl;

    int part_two_result = solve_part_two(data);
    std::cout << "Part Two Result: " << part_two_result << std::endl;

    return 0;
}
