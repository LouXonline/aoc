#include "aoc_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

char *aoc_read_file(const char *path) {
    FILE *f = fopen(path, "r");
    if (!f) {
        fprintf(stderr, "Failed to open %s\n", path);
        return NULL;
    }

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    rewind(f);

    char *buf = malloc(size + 1);
    if (!buf) {
        fprintf(stderr, "Failed to allocate memory for %s\n", path);
        fclose(f);
        return NULL;
    }

    fread(buf, 1, size, f);
    buf[size] = '\0';

    fclose(f);
    return buf;
}


char **aoc_split_lines(const char *s, size_t *out_count) {
    char *dup = strdup(s ? s : "");
    if (!dup) return NULL;
    size_t cap = 16, n = 0;
    char **arr = malloc(cap * sizeof *arr);
    if (!arr) { free(dup); return NULL; }
    char *save;
    char *tok = strtok_r(dup, "\n", &save);
    while (tok) {
        if (n == cap) {
            cap *= 2;
            char **tmp = realloc(arr, cap * sizeof *arr);
            if (!tmp) { /* cleanup */ while (n--) free(arr[n]); free(arr); free(dup); return NULL; }
            arr = tmp;
        }
        arr[n++] = strdup(tok);
        tok = strtok_r(NULL, "\n", &save);
    }
    free(dup);
    if (out_count) *out_count = n;
    return arr;
}

void aoc_free_str_array(char **arr, size_t n) {
    if (!arr) return;
    for (size_t i = 0; i < n; ++i) free(arr[i]);
    free(arr);
}

long aoc_parse_long(const char *s, int *ok) {
    char *end;
    errno = 0;
    long v = strtol(s, &end, 10);
    if (ok) *ok = (errno == 0 && end != s && *end == '\0');
    return v;
}