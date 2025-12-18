#!/bin/bash

# Check if script is sourced
if [[ "${BASH_SOURCE[0]}" == "${0}" ]]; then
    echo "ERROR: You must run this script with 'source setup.sh' or '. setup.sh'"
    exit 1
fi

# 1. Create virtual environment if missing
if [ ! -d ".venv" ]; then
    python3 -m venv .venv
    echo "Virtual environment created."
fi

# 2. Activate virtual environment
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

# 5. Optional: set PYTHONPATH to repo root
export PYTHONPATH="$(pwd)"
echo "PYTHONPATH set to: $PYTHONPATH"

echo ""
echo "Setup complete. Virtual environment is active (if it was sourced)"
echo "Run any solution with: python <year>/day<XX>/solution.py"
