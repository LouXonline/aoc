#ifndef AOC_UTILS_H
#define AOC_UTILS_H

#include <stddef.h>

char *aoc_read_file(const char *path); /* malloc'ed; free() after use */
char **aoc_split_lines(const char *s, size_t *out_count); /* malloc'ed array and strings */
void aoc_free_str_array(char **arr, size_t n);
long aoc_parse_long(const char *s, int *ok);

#endif /* AOC_UTILS_H */