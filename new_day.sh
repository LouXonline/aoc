#!/bin/bash
set -e

YEAR=$1
DAY=$(printf "%02d" "$2")

BASE_DIR="$(cd "$(dirname "$0")" && pwd)"
TEMPLATE_DIR="$BASE_DIR/templates"
BUILD_DIR="$BASE_DIR/build"

DAY_FOLDER="$BASE_DIR/$YEAR/day$DAY"
mkdir -p "$DAY_FOLDER"

declare -A FILES=(
  ["solution.py"]="solution.py.tpl"
  ["solution.c"]="solution.c.tpl"
  ["solution.cpp"]="solution.cpp.tpl"
  ["input.txt"]=""
  ["CMakeLists.txt"]="CMakeLists.txt.tpl"
)

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

# --- CMake step ---

mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

cmake ..
