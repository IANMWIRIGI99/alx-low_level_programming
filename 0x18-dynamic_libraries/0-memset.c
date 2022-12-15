#include "main.h"

/**
 * _memset - a function that fills memory with a constant byte.
 * @s: location to fill.
 * @b: char to fill location with.
 * @n: number of bytes to fill.
 * Return: returns a pointer to the memory area s.
 */
char *_memset(char *s, char b, unsigned int n)
{
	char *ptr = s;

	while (n--)
	{
		*s = b;
		s++;
	}
	return (ptr);
}
