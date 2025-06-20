#include <math.h>
#include <stdio.h>

/**
 * menger - prints a Menger sponge of a given level
 * @level: the level of the Menger sponge to print
 *
 * This function prints a Menger sponge pattern to the standard output.
 */

void menger(int level)
{
	if (level < 0)
	{
		return;
	}

	int size = pow(3, level);
	char character;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			character = '#';

			int row = i;
			int col = j;

			while (row || col)
			{
				if (row % 3 == 1 && col % 3 == 1)
				{
					character = ' ';
					break;
				}
				row /= 3;
				col /= 3;
			}
			printf("%c", character);
		}
	printf("\n");
	}
}
