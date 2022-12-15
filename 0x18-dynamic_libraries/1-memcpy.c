# include "main.h"

/**
 * _memcpy - a function that copies memory area.
 * @dest: memory area destination to copy.
 * @src: memory area source to copy from.
 * @n: number of bytes.
 * Return: returns a pointer to dest.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *ptr = dest;

	while (n--)
	{
		*dest = *src;
		src++;
		dest++;
	}
	return (ptr);
}
