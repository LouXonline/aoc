import sys
from pathlib import Path

# Add repo root to Python path so imports from root work
sys.path.append(str(Path(__file__).resolve().parents[2]))

from aoc_input import get_day_input

def solve_part_one(data):
    floor = 0
    for char in data:
        if char == '(':
            floor += 1
        elif char == ')':
            floor -= 1
    return floor

def solve_part_two(data):
    floor = 0
    for index, char in enumerate(data, start=1):
        if char == '(':
            floor += 1
        elif char == ')':
            floor -= 1
        if floor == -1:
            return index
    return -1  # If basement is never reached

if __name__ == "__main__":
    data = get_day_input()

    floor = solve_part_one(data)
    print(f"Final floor: {floor}")

    basement_position = solve_part_two(data)
    print(f"Position of first character to enter basement: {basement_position}")