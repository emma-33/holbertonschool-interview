#include "sort.h"

/**
 * get_max - Get max value of array
 * 
 * @array: array to check
 * @size: size of the array
 * 
 * Return: Max value in the array
 */

int get_max(int *array, size_t size)
{
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return (max);
}

/**
 * counter_help - Help counting sort in the array
 * 
 * @array: array to sort
 * @size: size of the array
 * @exp: digit to sort by
 */

void counter_help(int *array, size_t size, int exp)
{
    int *result;
    int count[10] = {0};
    ssize_t i;

    result = malloc(sizeof(int) * size);
    if (!result)
        return;

    for (i = 0; i < (ssize_t)size; i++)
        count[(array[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    
    for (i = (ssize_t)size - 1; i >= 0; i--)
    {
        result[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }
    for (i = 0; i < (ssize_t)size; i++)
        array[i] = result[i];
    
    free(result);
}

/**
 * radix_sort - Sort an array using the radix sort algorithm
 * 
 * @array: array to be sorted
 * @size: size of the array
 */

void radix_sort(int *array, size_t size)
{
    int max, exp;

    if (!array || size < 2)
        return;

    max = get_max(array, size);

    for (exp = 1; max / exp > 0; exp *= 10)
    {
        counter_help(array, size, exp);
        print_array(array, size);
    }
}