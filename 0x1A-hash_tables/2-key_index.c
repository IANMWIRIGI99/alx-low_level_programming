#include "hash_tables.h"

/**
 * key_index - function that gives you the index of a key
 * @key: The key, string
 * @size: The size of the array
 * Return: the index at which the key/value pair should be stored
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	/* % size complements our hash_djb2 function */
	return (hash_djb2(key) % size);
}
