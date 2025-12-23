cmake_minimum_required(VERSION 3.10)
project(AdventOfCode LANGUAGES C CXX)

add_subdirectory(common)

# Scan all C and C++ solution files
file(GLOB_RECURSE C_FILES RELATIVE ${CMAKE_SOURCE_DIR} "[0-9][0-9][0-9][0-9]/day*/solution.c")
file(GLOB_RECURSE CPP_FILES RELATIVE ${CMAKE_SOURCE_DIR} "[0-9][0-9][0-9][0-9]/day*/solution.cpp")

# For C targets
foreach(SRC ${C_FILES})
    get_filename_component(DAY_DIR ${SRC} DIRECTORY)
    get_filename_component(YEAR_FOLDER ${DAY_DIR} DIRECTORY)
    get_filename_component(DAY_FOLDER ${DAY_DIR} NAME)

    # Unique target name for CMake (internal)
    string(REPLACE "/" "_" TARGET_NAME "target_c_${YEAR_FOLDER}_${DAY_FOLDER}")

    add_executable(${TARGET_NAME} ${SRC})
    target_link_libraries(${TARGET_NAME} PRIVATE aoc_common_c)
    target_compile_definitions(${TARGET_NAME} PRIVATE
        AOC_DATA_DIR=${CMAKE_SOURCE_DIR}/${DAY_DIR}
    )

    # Output in build/YEAR/dayXX/ as "solution_c"
    set_target_properties(${TARGET_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${DAY_DIR}
        OUTPUT_NAME "solution_c"
    )
endforeach()

# For CPP targets
foreach(SRC ${CPP_FILES})
    get_filename_component(DAY_DIR ${SRC} DIRECTORY)
    get_filename_component(YEAR_FOLDER ${DAY_DIR} DIRECTORY)
    get_filename_component(DAY_FOLDER ${DAY_DIR} NAME)

    string(REPLACE "/" "_" TARGET_NAME "target_cpp_${YEAR_FOLDER}_${DAY_FOLDER}")

    add_executable(${TARGET_NAME} ${SRC})
    target_link_libraries(${TARGET_NAME} PRIVATE aoc_common_cpp)
    target_compile_definitions(${TARGET_NAME} PRIVATE
        AOC_DATA_DIR=${CMAKE_SOURCE_DIR}/${DAY_DIR}
    )
    target_include_directories(${TARGET_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/common)

    set_target_properties(${TARGET_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${DAY_DIR}
        OUTPUT_NAME "solution_cpp"
    )
endforeach()
