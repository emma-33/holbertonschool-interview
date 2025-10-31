#include <stdio.h>
#include "holberton.h"


/**
 * wildcmp - compares two strings
 *
 * @s1: first string
 * @s2: second string
 *
 * Return: 1 if the strings can be considered identical,
 * otherwise return 0
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '*')
	{
		if (*s1 && wildcmp(s1 + 1, s2))
			return (1);
		return (wildcmp(s1, s2 + 1));
	}
	if (*s1 != *s2)
		return (0);

	if (!*s1)
		return (1);

	return (wildcmp(s1 + 1, s2 + 1));
}
