import sys
from aoc_input import get_day_input
from pathlib import Path
import importlib.util

if len(sys.argv) != 3:
    print("Usage: python run_day.py YEAR DAY")
    sys.exit(1)

year = int(sys.argv[1])
day = int(sys.argv[2])

# Fetch input
data = get_day_input(year, day)
print(f"Input for {year} day {day} downloaded. Length = {len(data)}")

# Import solution dynamically
day_folder = Path(f"{year}/day{day:02d}/solution.py")
spec = importlib.util.spec_from_file_location("solution", day_folder)
solution = importlib.util.module_from_spec(spec)
spec.loader.exec_module(solution)
