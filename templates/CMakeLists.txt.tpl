# C solution
add_executable(solution_c solution.c)
target_link_libraries(solution_c PRIVATE aoc_common_c)

target_compile_definitions(solution_c PRIVATE
    AOC_DATA_DIR=${CMAKE_CURRENT_SOURCE_DIR}
)

# C++ solution
add_executable(solution_cpp solution.cpp)
target_link_libraries(solution_cpp PRIVATE aoc_common_cpp)

target_compile_definitions(solution_cpp PRIVATE
    AOC_DATA_DIR=${CMAKE_CURRENT_SOURCE_DIR}
)
