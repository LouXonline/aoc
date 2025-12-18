#!/bin/bash

# Usage: ./new_day.sh YEAR DAY
set -e

YEAR=$1
DAY=$(printf "%02d" "$2")

BASE_DIR="$(cd "$(dirname "$0")" && pwd)"
TEMPLATE_DIR="$BASE_DIR/templates"

DAY_FOLDER="$BASE_DIR/$YEAR/day$DAY"
mkdir -p "$DAY_FOLDER"

# Files and templates
declare -A FILES=(
  ["solution.py"]="solution.py.tpl"
  ["solution.c"]="solution.c.tpl"
  ["solution.cpp"]="solution.cpp.tpl"
  ["input.txt"]=""
)

# Create files
for TARGET in "${!FILES[@]}"; do
    DEST="$DAY_FOLDER/$TARGET"
    if [ -f "$DEST" ]; then
        echo "$DEST already exists. Skipping."
        continue
    fi

    TEMPLATE="${FILES[$TARGET]}"
    if [ -n "$TEMPLATE" ]; then
        cp "$TEMPLATE_DIR/$TEMPLATE" "$DEST"
        echo "Created $DEST from template."
    else
        touch "$DEST"
        echo "Created $DEST"
    fi
done

# Generate per-day CMakeLists.txt
CMAKE_FILE="$DAY_FOLDER/CMakeLists.txt"
if [ ! -f "$CMAKE_FILE" ]; then
    cat << 'EOF' > "$CMAKE_FILE"
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
EOF
    echo "Created $CMAKE_FILE"
else
    echo "$CMAKE_FILE already exists. Skipping."
fi

# Create build directory inside day folder
BUILD_DIR="$DAY_FOLDER/build"
if [ ! -d "$BUILD_DIR" ]; then
    mkdir -p "$BUILD_DIR"
    echo "Created build directory: $BUILD_DIR"
fi

# Optional: run cmake automatically
cd "$BUILD_DIR"
cmake ..
echo ""
echo "CMake configuration done in $BUILD_DIR. You can now run 'make' here to build C/C++ solutions."

cd "$BASE_DIR"