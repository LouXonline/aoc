#include "aoc_utils.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

namespace aoc {

std::string read_file(const std::string &path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Failed to open " << path << std::endl;
        return "";
    }

    std::stringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

} // namespace aoc
 