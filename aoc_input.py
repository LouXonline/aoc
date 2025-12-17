import os
from pathlib import Path
import requests
from dotenv import load_dotenv

# Load .env automatically
load_dotenv()

BASE_DIR = Path(__file__).parent

def get_day_input(year: int, day: int) -> str:
    day_folder = f"day{day:02d}"
    folder_path = BASE_DIR / str(year) / day_folder
    folder_path.mkdir(parents=True, exist_ok=True)

    input_file = folder_path / "input.txt"
    if input_file.exists():
        return input_file.read_text().strip()

    session = os.environ.get("AOC_SESSION")
    if not session:
        raise RuntimeError(
            "AOC_SESSION not set. Add it to .env or export it in your shell."
        )

    url = f"https://adventofcode.com/{year}/day/{day}/input"
    r = requests.get(url, cookies={"session": session})
    r.raise_for_status()

    input_file.write_text(r.text.strip())
    return r.text.strip()
