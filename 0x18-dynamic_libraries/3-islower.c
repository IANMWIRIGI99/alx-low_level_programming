#include "main.h"

/**
 * _islower - check the code.
 * @c: an input character.
 * Return: 0 or 1.
 */
int _islower(int c)
{
	char ch;
	int i = 0;

	for (ch = 'a'; ch <= 'z'; ++ch)
	{
		if (ch == c)
			i = 1;
	}
	return (i);
}
