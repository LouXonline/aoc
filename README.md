# Advent of Code Solutions

This repository contains my personal attempts to solve the Advent of Code challenges. It includes scripts to automatically download each day's input, cache it, and run the corresponding solution in an isolated Python environment.

---

## Repository Structure

aoc/
├── .gitignore
├── requirements.txt
├── setup.sh
├── aoc_input.py
└── 2015/
├── day01/
│   └── solution.py
└── day02/
└── solution.py

* `aoc_input.py` → Handles automatic input download and caching.
* `2015/dayXX/solution.py` → Individual solution files.
* `.venv/` → Python virtual environment (ignored by git).
* `.env` → Stores your Advent of Code session cookie (ignored by git).

---

## Setup Instructions (Ubuntu/Linux)

1. Clone the repository:

git clone <your_repo_url>
cd aoc

2. Run the setup script:

chmod +x setup.sh
source ./setup.sh

* Creates a virtual environment `.venv` if missing.
* Installs dependencies from `requirements.txt`.
* Creates `.env` file for your AoC session cookie if missing.

3. Add your AoC session cookie:

* Log in to [Advent of Code](https://adventofcode.com).
* Open browser developer tools → Application/Storage → Cookies → `session`.
* Copy the value and replace the placeholder in `.env`:

AOC_SESSION=your_session_cookie_here

---

4. Activate the virtual environment (if not already activated):

source .venv/bin/activate

* Ensures Python uses the local environment and installed dependencies.

---

5. Run any day's solution automatically:

python3 <YEAR>.day<XX>.py

Example:

python3 2015.day01.py

* Downloads the input if missing and caches it in `2015/day01/input.txt`.
* Runs the corresponding solution file automatically.

---

6. Writing new solutions:

* Create a folder for the day, e.g., `2015/day02/`.
* Add `solution.py` with a `solve(data)` function:

# 2015/day01/solution.py

def solve(data):
# Your solution here
print(len(data))

if **name** == "**main**":
from aoc_input import get_day_input
input_data = get_day_input()
solve(input_data)

* `run_day.py` will automatically run this solution.

---

7. Notes:

* `.gitignore` ensures the following are **not committed**:

**pycache**/
*.pyc
.venv/
**/input.txt
.env

* `.env` keeps your session cookie private.
* Inputs are cached per day to avoid repeated downloads.
* Python uses the virtual environment `.venv` to isolate dependencies.

---

8. Optional:

* To persist `AOC_SESSION` in your shell permanently:

echo 'export AOC_SESSION="your_session_cookie_here"' >> ~/.bashrc
source ~/.bashrc

* Not needed if using `.env` with `python-dotenv`.

---

This setup allows anyone to clone the repo, run setup, and immediately execute any day's solution with cached inputs.
