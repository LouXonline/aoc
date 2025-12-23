add_library(aoc_common_c STATIC src/aoc_utils.c)

target_include_directories(aoc_common_c PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(aoc_common_cpp STATIC src/aoc_utils.cpp)

target_include_directories(aoc_common_cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)