#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

void radix_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
int get_max(int *array, size_t size);
void counter_help(int *array, size_t size, int exp);


#endif