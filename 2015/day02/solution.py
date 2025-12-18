from aoc_input import get_day_input

def solve_part_one(data):
    total_wrapping = 0
    for present in data.splitlines():
        dimensions = list(map(int, present.split('x')))
        l, w, h = dimensions
        side_areas = [l * w, w * h, h * l]
        surface_area = 2 * sum(side_areas)
        slack = min(side_areas)
        total_wrapping += surface_area + slack
    return total_wrapping

def solve_part_two(data):
    total_ribbon = 0
    for present in data.splitlines():
        dimensions = list(map(int, present.split('x')))
        dimensions.sort()
        perimeter = 2 * (dimensions[0] + dimensions[1])
        bow = dimensions[0] * dimensions[1] * dimensions[2]
        total_ribbon += perimeter + bow
    return total_ribbon

if __name__ == "__main__":
    data = get_day_input()

    total_wrapping = solve_part_one(data)
    print(f"Total wrapping paper needed: {total_wrapping}")

    total_ribbon = solve_part_two(data)
    print(f"Total ribbon needed: {total_ribbon}")