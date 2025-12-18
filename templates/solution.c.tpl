#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        perror("Failed to open input.txt");
        return 1;
    }

    char buffer[256];
    int line_count = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        line_count++;
        // process line here
    }

    fclose(file);

    printf("Input lines: %d\n", line_count);
    return 0;
}
