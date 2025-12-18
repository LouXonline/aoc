#!/bin/bash
set -e

# 0. Script root folder
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# 1. Detect YEAR/DAY
CUR_DIR=$(pwd)
BASENAME=$(basename "$CUR_DIR")
PARENT=$(basename "$(dirname "$CUR_DIR")")

if [[ "$BASENAME" =~ day([0-9][0-9]) ]] && [[ "$PARENT" =~ ^[0-9]{4}$ ]]; then
    YEAR="$PARENT"
    DAY="${BASENAME:3:2}"
    shift 0
else
    if [ "$#" -lt 2 ]; then
        echo "Usage: $0 YEAR DAY [args...]"
        exit 1
    fi
    YEAR=$1
    DAY=$(printf "%02d" $2)
    shift 2
fi

ARGS="$@"

# 2. Absolute paths relative to script
DAY_FOLDER="$SCRIPT_DIR/$YEAR/day$DAY"
BUILD_DIR="$DAY_FOLDER/build"

# 3. Ensure build folder exists
mkdir -p "$BUILD_DIR"

# 4. Configure build with CMake
cd "$BUILD_DIR"
cmake "$DAY_FOLDER"

# 5. Build C and C++ executables if they exist
if [ -f "$DAY_FOLDER/solution.c" ]; then
    make solution_c
fi

# if [ -f "$DAY_FOLDER/solution.cpp" ]; then
#     make solution_cpp
#fi

# 6. Run the executables from the day folder
cd "$DAY_FOLDER"

if [ -f "build/solution_c" ]; then
    echo "Running C executable..."
    ./build/solution_c $ARGS
fi

# if [ -f "build/solution_cpp" ]; then
#     echo "Running C++ executable..."
#     ./build/solution_cpp $ARGS
# fi
