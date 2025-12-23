# Advent of Code Solutions

This repository contains my personal attempts to solve Advent of Code challenges. It includes solutions in Python, C, and C++, with scripts to automatically handle input downloading, caching, and compilation.

## Repository Structure

aoc/
├── .gitignore
├── requirements.txt
├── setup.sh           # Setup script to create Python environment and dependencies
├── new_day.sh         # Script to create a new day's folder and solution templates
├── aoc_input.py       # Python helper for downloading and caching input
├── common/            # Shared C/C++ utilities
├── templates/         # Templates used by new_day.sh
├── 2015/
│   ├── day01/
│   │   ├── solution.py
│   │   ├── solution.c
│   │   └── solution.cpp
│   └── day02/
│       └── solution.py
└── build/             # Build folder for C/C++ executables (created by CMake)

- `setup.sh` → Sets up the Python virtual environment `.venv`, installs dependencies from `requirements.txt`, and creates `.env` for your AoC session cookie.  
- `new_day.sh` → Automates creation of a new day's folder with solution templates for Python, C, and C++, and an empty `input.txt`.  
- `aoc_input.py` → Handles downloading and caching input for Python solutions.  
- `common/` → Shared C/C++ utilities (headers and source files).  
- `templates/` → Template files for new Python, C, and C++ solutions.  
- `2015/dayXX/solution.py` → Python solution for a specific day.  
- `2015/dayXX/solution.c / .cpp` → C/C++ solutions for a specific day.  
- `build/` → Build folder for C/C++ executables. All C/C++ solutions are compiled from the root `CMakeLists.txt`.

---

## Setup Instructions (Ubuntu/Linux/macOS)

1. Clone the repository:

```bash
git clone <your_repo_url>
cd aoc
```

2. Run the setup script:

```bash
# Only needed if you get permission errors
# chmod +x setup.sh
source ./setup.sh
```

- Creates a Python virtual environment `.venv` if missing.  
- Installs dependencies from `requirements.txt`.  
- Creates `.env` for your Advent of Code session cookie if missing.  

> **Note:** `chmod +x` is only needed if you see “Permission denied” errors when running the script. On Windows, it is generally not required; you can run `bash setup.sh` directly.

---

## Setting up your AoC session cookie (optional but recommended)

All solutions (Python, C, C++) read `input.txt`. The Python helper `aoc_input.py` can automatically download the input if you have set your session cookie.  

**Steps to get your session cookie:**

1. Log in to [Advent of Code](https://adventofcode.com).  
2. Open your browser’s developer tools:  
   - **Chrome/Edge:** `F12` → Application → Storage → Cookies → `adventofcode.com`  
   - **Firefox:** `F12` → Storage → Cookies → `adventofcode.com`  
   - **Safari:** Develop → Show Web Inspector → Storage → Cookies  
3. Find the cookie named `session`.  
4. Copy its value.  
5. Paste it into `.env` in the project root:

```text
AOC_SESSION=your_session_cookie_here
```

> If the cookie is set, Python solutions will automatically download `input.txt` for the day.  
> If no cookie is provided, `input.txt` is still created by `new_day.sh` in the correct `year/day` folder; you can manually copy the input from the website into this file.

---

## Creating a New Day

1. Use the `new_day.sh` script to create a folder for the day with all templates:

```bash
# Only needed if you get permission errors
# chmod +x new_day.sh
./new_day.sh 2015 03
```

- This will automatically create `2015/day03/` with:
  - `solution.py` → Python solution template using `aoc_input.py` to get the input.
  - `solution.c` → C solution template.
  - `solution.cpp` → C++ solution template.
  - `input.txt` → empty file.  

> **All template files are automatically written by the script. No manual saving is required** after running it. You only need to edit the files to implement your solutions.

2. Example Python template:

```python
# 2015/day03/solution.py
def solve(data):
    # Your solution here
    print(len(data))

if __name__ == "__main__":
    from aoc_input import get_day_input
    data = get_day_input()
    solve(data)
```

---

## Running Python Solutions

1. Input files are cached per day in the corresponding folder, e.g., `2015/day03/input.txt`.  
2. Run a solution:

```bash
python3 2015/day03/solution.py
```

- Requires that the `.env` session cookie is set (optional but recommended) and `.venv` is activated.  
- If no cookie is set, Python will still attempt to read `input.txt` if you manually added it.

---

## Running C/C++ Solutions

1. Create a build folder (if not already):

```bash
mkdir -p build
cd build
```

2. Generate CMake build files from the root folder:

```bash
cmake ..
```

- Automatically detects all `solution.c` and `solution.cpp` files in the project and links them with `common` utilities.

3. Build all executables with `make`:

```bash
make
```

- Executables are generated in `build/<year>/dayXX/` with names:
  - `solution_c` → C
  - `solution_cpp` → C++

4. Run a C solution:

```bash
./2015/day03/solution_c
```

- Reads `input.txt` from the corresponding day folder via the `AOC_DATA_DIR` macro.

5. Run a C++ solution:

```bash
./2015/day03/solution_cpp
```

---

## Notes

- `.gitignore` ensures the following are not committed:

```
# Advent of Code
**input.txt
.env

# Build artifacts
*build/

# Python
__pycache__/
*.pyc

# Virtual environment
.venv/

# Visual Studio Code
.vscode/
```

- `.env` keeps your AoC session private.  
- Inputs are cached per day to avoid repeated downloads.  
- Python virtual environment `.venv` isolates dependencies.  
- CMake automatically organizes build outputs by day and year.  

---

## Optional

- Persist `AOC_SESSION` permanently in your shell:

```bash
echo 'export AOC_SESSION="your_session_cookie_here"' >> ~/.bashrc
source ~/.bashrc
```

- Not required if using `.env` with python-dotenv.
