from aoc_input import get_day_input

def solve(data):
    floor = 0
    for char in data:
        if char == '(':
            floor += 1
        elif char == ')':
            floor -= 1
    print(f"Final floor: {floor}")

if __name__ == "__main__":
    data = get_day_input()
    solve(data)