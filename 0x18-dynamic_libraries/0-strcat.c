#include "main.h"

/**
 * _strcat - check the code.
 * @dest: an input string.
 * @src: an input string.
 * Return: a pointer to the resulting string dest.
 */
char *_strcat(char *dest, char *src)
{
	char *temp = dest;

	while (*dest)
		dest++;

	while (*src)
		*dest++ = *src++;

	*dest = '\0';
	return (temp);
}
