#include "hash_tables.h"

/**
 * hash_table_set - function that adds an element to the hash table
 * @ht: A pointer to hash table to set in.
 * @key: The key, string
 * @value: The value associated with the key
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	char *dup_val, *dup_key;
	hash_node_t *node, *tmp;

	if (ht == NULL || key == NULL || value == NULL)
		return (0);
	else if (strlen(key) == 0)
		return (0);
	dup_val = strdup(value);
	dup_key = strdup(key);
	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
		return (0);
	node->key = dup_key;
	node->value = dup_val;
	node->next = NULL;
	index = key_index((unsigned char *)key, ht->size);
	if (ht->array[index] != NULL)
	{
		tmp = ht->array[index];
		while (tmp != NULL)
		{
			if (strcmp(tmp->key, dup_key) == 0)
			{
				free(ht->array[index]->value);
				ht->array[index]->value = dup_val;
				free(dup_key);
				free(node);
				return (1);
			}
			tmp = tmp->next;
	}
	tmp = ht->array[index];
	node->next = tmp;
	ht->array[index] = node;
	}
	else
		(ht->array)[index] = node;
	return (1);
}
