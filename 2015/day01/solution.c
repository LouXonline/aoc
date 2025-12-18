#include <stdio.h>
#include <stdlib.h>

int solve_part_one(const char *data) {
    int floor = 0;

    for (const char *ptr = data; *ptr != '\0'; ptr++) {
        if (*ptr == '(') {
            floor++;
        } else if (*ptr == ')') {
            floor--;
        }
    }
    return floor;
}

int main(void) {
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        perror("Failed to open input.txt");
        return 1;
    }

    // turn file content into string
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    if (size == -1) {
        perror("ftell failed");
        fclose(file);
        return 1;
    }
    fseek(file, 0, SEEK_SET);
    char *data = malloc((size_t)size + 1);
    if (!data) {
        perror("Failed to allocate memory");
        fclose(file);
        return 1;
    }

    size_t nread = fread(data, 1, (size_t)size, file);
    data[nread] = '\0';

    int floor = solve_part_one(data);

    fclose(file);

    printf("Final floor: %d\n", floor);
    return 0;
}
