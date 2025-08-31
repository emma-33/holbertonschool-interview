#include "holberton.h"

/**
 * _is_digit - checks if a string is a digit
 * @s: string to check
 * Return: 1 if s is a digit, 0 otherwise
 */

int _is_digit(char *s)
{
	int i = 0, digit = 0;

	while (s[i] != '\0')
	{
		if (!isdigit((unsigned char)s[i]))
			digit = 0;
		else
			digit = 1;
		i++;
	}
	return (digit);
}

/**
 * print_number - prints a number in an array
 * @num: array of digits
 * @size: size of the array
 */
void print_number(int *num, int size)
{
	int i = 0;

	while (i < size && num[i] == 0)
	{
		i++;
	}

	if (i == size)
	{
		_putchar('0');
	}
	else
	{
		for (; i < size; i++)
		{
			_putchar(num[i] + '0');
		}
	}
	_putchar('\n');
}


/**
 * main - Program that multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 98 on error
 */

int main(int argc, char *argv[])
{
	char *num1 = argv[1], *num2 = argv[2], *error = "Error\n";
	int i = 0;

	if (_is_digit(num1) == 0 || _is_digit(num2) == 0 || argc != 3)
	{
		for (i = 0; error[i] != '\0'; i++)
		{
			_putchar(error[i]);
		}
		return (98);
	}
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int len = len1 + len2;

	int *result = malloc(sizeof(int) * len);

	if (result == NULL)
		exit(98);

	for (int i = 0; i < len; i++)
		result[i] = 0;

	for (int i = len1 - 1; i >= 0; i--)
	{
		for (int j = len2 - 1; j >= 0; j--)
		{
			int mul = (num1[i] - '0') * (num2[j] - '0');
			int sum = mul + result[i + j + 1];

			result[i + j + 1] = sum % 10;
			result[i + j] += sum / 10;

		}
	}

	print_number(result, len);
	free(result);
	return (0);
}
