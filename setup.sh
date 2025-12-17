#!/bin/bash

# 1. Create virtual environment if missing
if [ ! -d ".venv" ]; then
    python3 -m venv .venv
    echo "Virtual environment created."
fi

# 2. Activate virtual environment
source .venv/bin/activate
echo "Virtual environment acivated."

# 3. Upgrade pip and install dependencies
echo "Upgrading pip and installing dependencies..."
pip install --upgrade pip
pip install -r requirements.txt

# 4. Create .env if missing
if [ ! -f ".env" ]; then
    echo "AOC_SESSION=YOUR_SESSION_COOKIE_HERE" > .env
    echo ".env file created. Replace YOUR_SESSION_COOKIE_HERE with your AoC session cookie."
fi

echo "Setup complete. Activate venv with: source .venv/bin/activate"
