#include "regex.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * regex_match - Checks whether a given pattern matches a given string
 * @str: string to scan
 * @pattern: regex
 * Return: 1 if regex matches string else 0
*/

int regex_match(char const *str, char const *pattern)
{
	if (!str || !pattern)
		return (0);

	if (*pattern == '\0')
		return (*str == '\0');

	if (pattern[1] == '*')
	{
		if (regex_match(str, pattern + 2))
			return (1);

		if (*str != '\0' && (*str == *pattern || *pattern == '.'))
			return (regex_match(str + 1, pattern));

		return (0);
	}

	if (*str != '\0' && (*str == *pattern || *pattern == '.'))
		return (regex_match(str + 1, pattern + 1));

	return (0);
}