import sys
from pathlib import Path

# Add repo root to Python path so imports from root work
sys.path.append(str(Path(__file__).resolve().parents[2]))

from aoc_input import get_day_input

def solve(data):
    print(f"Input length: {len(data)}")
    # your solution here

if __name__ == "__main__":
    data = get_day_input()
    solve(data)
