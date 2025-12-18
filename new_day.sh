#!/bin/bash

# Usage: ./new_day.sh YEAR DAY
YEAR=$1
DAY=$(printf "%02d" $2)

# Create day folder
DAY_FOLDER="$YEAR/day$DAY"
mkdir -p "$DAY_FOLDER"

# Path to solution.py
SOLUTION_FILE="$DAY_FOLDER/solution.py"

# Only create file if it doesn't exist
if [ ! -f "$SOLUTION_FILE" ]; then
    cat << EOF > "$SOLUTION_FILE"
from aoc_input import get_day_input

def solve(data):
    print(f"Input length: {len(data)}")
    # your solution here

if __name__ == "__main__":
    data = get_day_input()
    solve(data)
EOF
    echo "Created $SOLUTION_FILE with template."
else
    echo "$SOLUTION_FILE already exists. Skipping."
fi
