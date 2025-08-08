#include "search_algos.h"
#include <stdio.h>
#include <stddef.h>

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * using the advanced binary search algorithm.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 * Return: The index of the first occurrence of value in the array,
 *         or -1 if value is not present or the array is NULL.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	if (size == 1)
		return (1);

	int beg = 0;
	int end = size - 1;

	return (helper_binary_search(array, beg, end, value));
}

/**
 * helper_binary_search - Helps with the recursive binary search.
 * @array: Pointer to the first element of the array to search in.
 * @beg: The starting index of the current search range.
 * @end: The ending index of the current search range.
 * @value: The value to search for.
 *
 * Return: The index of the first occurrence of value in the array,
 *         or -1 if value is not present in the array.
 */

int helper_binary_search(int *array, int beg, int end, int value)
{
	if (end >= beg)
	{
		print_array(array, beg, end);

		int half = beg + (end - beg) / 2;
		if (array[half] == value && array[half - 1] != value)
			return (half);

		if (array[half] >= value)
			return (helper_binary_search(array, beg, half - 1, value));

		return (helper_binary_search(array, half + 1, end, value));
	}
	return (-1);
}

/**
 * print_array - Prints an array of integers.
 * @array: Pointer to the first element of the array.
 * @beg: The starting index of the array to print.
 * @end: The ending index of the array to print.
 * Return: void
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
