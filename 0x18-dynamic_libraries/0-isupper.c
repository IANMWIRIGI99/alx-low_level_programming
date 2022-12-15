#include "main.h"

/**
 * _isupper - check the code.
 * @c: an input character.
 * Return: 0 or 1.
 */
int _isupper(int c)
{
	char C = 'A';
	int i = 0;

	for (; C <= 'Z'; C++)
	{
		if (c == C)
		{
			i = 1;
			break;
		}
	}

	return (i);
}
