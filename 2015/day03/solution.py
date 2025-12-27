import sys
from pathlib import Path

# Add repo root to Python path so imports from root work
sys.path.append(str(Path(__file__).resolve().parents[2]))

from aoc_input import get_day_input

def solve_part_one(data):
    x, y = 0, 0
    visited = {(x, y)}

    for move in data.strip():
        if move == '^':
            y += 1
        elif move == 'v':
            y -= 1
        elif move == '>':
            x += 1
        elif move == '<':
            x -= 1
        visited.add((x, y))

    return len(visited)

def solve_part_two(data):
    positions = [(0, 0), (0, 0)]  # Santa and Robo-Santa
    visited = {(0, 0)}

    for i, move in enumerate(data.strip()):
        idx = i % 2
        x, y = positions[idx]

        if move == '^':
            y += 1
        elif move == 'v':
            y -= 1
        elif move == '>':
            x += 1
        elif move == '<':
            x -= 1

        positions[idx] = (x, y)
        visited.add((x, y))

    return len(visited)

if __name__ == "__main__":
    data = get_day_input()

    part_one_result = solve_part_one(data)
    print(f"Part One: {part_one_result}")

    part_two_result = solve_part_two(data)
    print(f"Part Two: {part_two_result}")