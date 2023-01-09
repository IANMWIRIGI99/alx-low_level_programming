#include "hash_tables.h"

/**
  * hash_djb2 - hash function implementing the djb2 algorithm
  * @str: The input string
  * Return: hash
  */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	/**
	  * str++ is going to the next address in memory,where the next
	  * char in the string is stored
	  */
	while ((c = *str++))
	{
		/* hash << 5 = hash * 2^5 */
		hash = ((hash << 5) + hash) + c;    /* hash * 33 + c */
	}

	return (hash);
}
