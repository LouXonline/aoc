# Auto-generated CMakeLists.txt from new_day.sh
cmake_minimum_required(VERSION 3.10)
project(AoCDay LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find C sources
file(GLOB C_SOURCES "*.c")
foreach(src ${C_SOURCES})
    get_filename_component(fname ${src} NAME_WE)
    add_executable(${fname}_c ${src})
endforeach()

# Find C++ sources
file(GLOB CPP_SOURCES "*.cpp")
foreach(src ${CPP_SOURCES})
    get_filename_component(fname ${src} NAME_WE)
    add_executable(${fname}_cpp ${src})
endforeach()
