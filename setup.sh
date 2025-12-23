#!/bin/bash

# Check if script is sourced
if [[ "${BASH_SOURCE[0]}" == "${0}" ]]; then
    echo "ERROR: You must run this script with 'source setup.sh' or '. setup.sh'"
    exit 1
fi

# 1. Create virtual environment if missing
if [ ! -d ".venv" ]; then
    echo "Creating virtual environment..."
    python3 -m venv .venv
    echo "Virtual environment created."
fi

# 2. Activate virtual environment
echo "Activating virtual environment..."
source .venv/bin/activate
echo "Virtual environment activated."

# 3. Upgrade pip & install dependencies
echo "Upgrading pip and installing dependencies..."
pip install --upgrade pip
pip install -r requirements.txt

# 4. Create .env if missing
if [ ! -f ".env" ]; then
    echo "AOC_SESSION=YOUR_SESSION_COOKIE_HERE" > .env
    echo ".env created. Replace YOUR_SESSION_COOKIE_HERE with your AoC session cookie."
fi

# 5. Create build directory if missing
if [ ! -d "build" ]; then
    echo "Creating build directory..."
    mkdir build
    echo "Build directory created."
fi

# 6. Run CMake to generate build files
echo "Running CMake to generate build files..."
cd build
cmake ..
cd ..
echo "CMake configuration complete."

# Optional: set PYTHONPATH to repo root
# export PYTHONPATH="$(pwd)"
# echo "PYTHONPATH set to: $PYTHONPATH"

echo ""
echo "Setup complete. Virtual environment is active."
echo "Make sure you have set up your .env file with your AoC session cookie."
echo "AOC_SESSION value can be found in your browser cookies after logging into Advent of Code."
echo ""
echo "Run any python solution with: python3 <YEAR>/day<XX>/solution.py"
echo "For example: python3 2015/day01/solution.py"
echo ""
echo "Run any C solution with: make -C <YEAR>/day<XX> in the build directory."
echo "For example: TO BE WRITTEN"
echo ""
echo "Happy coding!"
echo ""