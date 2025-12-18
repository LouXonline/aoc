import os
from pathlib import Path
import requests

BASE_DIR = Path(__file__).parent.resolve()

# Load AOC_SESSION from .env if exists
env_path = BASE_DIR / ".env"
if env_path.exists():
    with open(env_path) as f:
        for line in f:
            if line.startswith("AOC_SESSION="):
                os.environ["AOC_SESSION"] = line.strip().split("=", 1)[1]

def get_day_input(year: int = None, day: int = None) -> str:
    """
    Fetch AoC input for a given year/day.
    If year/day are not provided, infer them from the folder of the calling script.
    Caches input locally in BASE_DIR/year/dayXX/input.txt
    """
    # Auto-detect year/day if not provided
    if year is None or day is None:
        # Path of the calling script
        import inspect
        caller_file = Path(inspect.stack()[1].filename).resolve()
        parts = caller_file.parts
        try:
            # Expect structure: repo_root / YEAR / dayXX / solution.py
            day_index = next(i for i, p in enumerate(parts) if p.startswith("day"))
            if year is None:
                year = int(parts[day_index - 1])
            if day is None:
                day = int(parts[day_index].replace("day", ""))
        except Exception:
            raise RuntimeError(
                "Could not determine year/day from folder structure. "
                "Please provide them explicitly as arguments."
            )

    # Folder to store input
    day_folder = BASE_DIR / f"{year}/day{day:02d}"
    day_folder.mkdir(parents=True, exist_ok=True)
    input_file = day_folder / "input.txt"

    # Return cached input if exists
    if input_file.exists():
        return input_file.read_text().strip()

    # Fetch from AoC
    session = os.environ.get("AOC_SESSION")
    if not session:
        raise RuntimeError("AOC_SESSION environment variable not set")

    url = f"https://adventofcode.com/{year}/day/{day}/input"
    response = requests.get(url, cookies={"session": session})
    if response.status_code != 200:
        raise RuntimeError(f"Failed to fetch input: {response.status_code}")

    # Save locally
    input_file.write_text(response.text.strip())
    return response.text.strip()
