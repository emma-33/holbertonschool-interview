#include <stdio.h>
#include <stddef.h>
#include "search_algos.h"


/**
 * print_array - Print the array or sub-array
 *
 * @array: Pointer to the first element of the array
 * @beg: index of the first element
 * @end: index of the last element
 */
void print_array(int *array, int beg, int end)

{
	printf("Searching in array: ");
	for (int i = beg; i <= end; i++)
	{
		printf("%d", array[i]);
		if (i != end)
			printf(", ");
	}
	printf("\n");
}


/**
 * search - Searches for a value in a sorted array of integers
 *
 * @array: Pointer to the first element of the array
 * @beg: index of the first element
 * @end: index of the last element
 * @value: Value to search for
 * Return: index of the value or -1 if failed
 */
int search(int *array, int beg, int end, int value)

{
	if (end >= beg)
	{
		print_array(array, beg, end);
		int half = beg + (end - beg) / 2;

		if (array[half] == value && array[half - 1] != value)
			return (half);

		if (array[half] >= value)
			return (search(array, beg, half, value));

		return (search(array, half + 1, end, value));
	}
	return (-1);
}


/**
 * advanced_binary - Call the function search
 *
 * @array: Pointer to the first element of the array
 * @size: Number of elements in array
 * @value: Value to search for
 * Return: index of the value or -1 if failed
 */
int advanced_binary(int *array, size_t size, int value)

{
	if (array == NULL || size == 0)
		return (-1);
	if (size == 1)
		return (1);
	int beg = 0, end = size - 1;

	return (search(array, beg, end, value));
}
