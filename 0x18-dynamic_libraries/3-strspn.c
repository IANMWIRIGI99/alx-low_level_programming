#include "main.h"

/**
 * _strspn - a function that gets the length of a prefix substring.
 * @s: an input string.
 * @accept: an input character with to locate into string s.
 * Return: returns pointer to c position.
 */
unsigned int _strspn(char *s, char *accept)
{
	int i, j, d = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] != 32)
		{
			for (j = 0; accept[j] != '\0'; j++)
			{
				if (s[i] == accept[j])
					d++;
			}
		}
		else
			return (d);
	}
	return (d);
}
