#include "main.h"

/**
 * _strncpy - check the code.
 * @dest: an input  string.
 * @src: an input string.
 * @n: an input integer.
 * Return: a pointer to the resulting string.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}
