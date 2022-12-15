#include "main.h"

/**
 * _isalpha - check the code.
 * @c: an input character.
 * Return: 0 or 1.
 */
int _isalpha(int c)
{
	char ch, Ch;
	int i = 0;

	for (ch = 'a'; ch <= 'z'; ++ch)
	{
		for (Ch = 'A'; Ch <= 'Z'; ++Ch)
		{
			if (c == ch || c == Ch)
				i = 1;
		}
	}
	return (i);
}
