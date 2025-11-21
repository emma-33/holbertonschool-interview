#include "substring.h"
#include <stdlib.h>
#include <string.h>

/**
 * is_valid - Helper function to check sub string
 * @s: string to scan
 * @start: index start
 * @words: array of words
 * @nb_words: number of elements in the array words
 * @word_len: length of the word
 * @expected: expected size
 * @current: current size
 * Return: 1 if valid else 0
 */

int is_valid(const char *s, int start, const char **words, int nb_words,
	int word_len, int *expected, int *current)
{
	int j, k;


	for (j = 0; j < nb_words; j++)
	{
		const char *chunk = s + start + j * word_len;
		int found = -1;

		for (k = 0; k < nb_words; k++)
		{
			if (strncmp(chunk, words[k], word_len) == 0)
			{
				found = k;
				break;
			}
		}
		if (found == -1)
			return (0);
		current[found]++;
		if (current[found] > expected[found])
			return (0);
	}
	return (1);
}

/**
*  find_substring - finds all the possible substrings containing
* a list of words, within a given string
* @s: string to scan
* @words: array of words with all substrings
* @nb_words: number of elements in the array words
* @n: address at which to store the number of elements in the returned array
* Return: allocated array with index in s where substring was found or NULL
*/

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int i, j;
	int word_len, string_len, sub_len, count = 0;
	int expected[nb_words], current[nb_words];
	int *result;

	if (!s || !words || !(*words) || nb_words <= 0 || !n)
		return (NULL);

	word_len = strlen(words[0]);
	string_len = strlen(s);
	sub_len = nb_words * word_len;

	if (string_len < sub_len)
		return (NULL);

	result = malloc(sizeof(int) * string_len);
	if (!result)
		return (NULL);

	memset(expected, 0, sizeof(int) * nb_words);
	for (i = 0; i < nb_words; i++)
		for (j = 0; j < nb_words; j++)
			if (strcmp(words[i], words[j]) == 0)
				expected[i]++;

	for (i = 0; i <= string_len - sub_len; i++)
	{
		memset(current, 0, sizeof(int) * nb_words);
		if (is_valid(s, i, words, nb_words, word_len, expected, current))
			result[count++] = i;
	}

	if (count == 0)
	{
		free(result);
		return (NULL);
	}

	*n = count;
	return (result);
}
