#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stddef.h>


int advanced_binary(int *array, size_t size, int value);
int helper_binary_search(int *array, int beg, int end, int value);
void print_array(int *array, int beg, int end);

#endif /* SEARCH_ALGOS_H */
