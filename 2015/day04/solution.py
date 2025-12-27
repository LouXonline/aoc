import sys
from pathlib import Path

# Add repo root to Python path so imports from root work
sys.path.append(str(Path(__file__).resolve().parents[2]))

from aoc_input import get_day_input

def solve(data):
    import hashlib
    number = 0
    part_one_found = False
    part_one_result = None

    while True:
        test_str = f"{data.strip()}{number}".encode()
        hash_result = hashlib.md5(test_str).hexdigest()

        if not part_one_found and hash_result.startswith("00000"):
            part_one_result = number
            part_one_found = True
            return part_one_result  # Return after finding part one
            break

        number += 1    

if __name__ == "__main__":
    data = get_day_input()

    part_one_result = solve(data)
    print(f"Part One: {part_one_result}")