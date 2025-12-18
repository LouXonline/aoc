#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open input.txt\n";
        return 1;
    }

    std::string line;
    int line_count = 0;

    while (std::getline(file, line)) {
        line_count++;
        // process line here
    }

    std::cout << "Input lines: " << line_count << std::endl;
    return 0;
}
