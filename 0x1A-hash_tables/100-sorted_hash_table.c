#include "hash_tables.h"

/**
 * shash_table_create - function that creates a hash table
 * @size: The size of the array
 * Return: a pointer to the newly created hash table or NULL
 */

 /* the entire structure size must be known to the compiler */
shash_table_t *shash_table_create(unsigned long int size)
{
	unsigned long int i;
	shash_table_t *shash_table;

	shash_table = malloc(sizeof(shash_table_t));
	if (shash_table == NULL)
		return (NULL);
	/* setting members of the shash_table_t struct */
	shash_table->size = size;
	shash_table->array = malloc(sizeof(shash_node_t *) * size);
	if (shash_table->array == NULL)
	{
		free(shash_table);
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		/* all entries of the table set to empty */
		(shash_table->array)[i] = NULL;
	}

	return (shash_table);
}

/**
 * insert_to_sorted_list - inserts a node to the sorted linked list by key's ASCII
 * @sht: The sorted hash table
 * @node: The node to be inserted
 * Return: void
 */
void insert_to_sorted_list(shash_table_t *sht, shash_node_t *node)
{
	shash_node_t *tmp;

	if (sht->shead == NULL && sht->stail == NULL)
	{
		sht->shead = sht->stail = node;
		return;
	}
	tmp = sht->shead;
	while (tmp != NULL)
	{
		if (strcmp(node->key, tmp->key) < 0)
		{
			node->snext = tmp;
			node->sprev = tmp->sprev;
			tmp->sprev = node;
			if (node->sprev != NULL)
				node->sprev->snext = node;
			else
				sht->shead = node;
			return;
		}
		tmp = tmp->snext;
	}
	node->sprev = sht->stail;
	sht->stail->snext = node;
	sht->stail = node;
}

/**
 * shash_table_set - function that adds an element to the hash table
 * @ht: A pointer to hash table to set in
 * @key: The key, string
 * @value: The value associated with the key
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	char *dup_val, *dup_key;
	shash_node_t *node, *tmp;

	if (ht == NULL || key == NULL || value == NULL)
		return (0);
	else if (strlen(key) == 0)
		return (0);
	dup_val = strdup(value);
	dup_key = strdup(key);
	node = malloc(sizeof(shash_node_t));
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
	insert_to_sorted_list(ht, node);
	return (1);
}

/**
 * shash_table_get - function that retrieves a value associated with a key
 * @ht: The hash table you want to look into
 * @key: The key you are looking for
 * Return: the value associated with element, or NULL if key not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	char *value = NULL;
	shash_node_t *node;

	if (ht == NULL || key == NULL)
		return (NULL);
	else if (strlen(key) == 0)
		return (NULL);

	index = key_index((unsigned char *)key, ht->size);
	if ((ht->array)[index] == NULL)
		return (NULL);

	node = ht->array[index];
	while (!value)
	{
		if (strcmp(node->key, key) == 0)
			value = node->value;
		node = node->next;
	}
	return (value);
}

/**
 * shash_table_print - function that prints a hash table
 * @ht: The hash table
 *
 * Return: void
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;
	char flag = 0;  /* if data not yet printed */

	if (ht == NULL || ht->array == NULL)
		return;
	putchar('{');
	node = ht->shead;
	while (node != NULL)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		flag = 1;
		node = node->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints a sorted hash table in reverse
 * @ht: The hash table
 *
 * Return: void
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *tmp;
	char flag = 0; /* 0 if no data printed yet */

	if (ht == NULL || ht->array == NULL)
		return;
	printf("{");
	tmp = ht->stail;
	while (tmp != NULL)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", tmp->key, tmp->value);
		flag = 1;
		tmp = tmp->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - function that deletes a hash table
 * @ht: The hash table
 *
 * Return: void
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *node;
	shash_node_t *next;

	if (ht == NULL)
		return;
	if (ht->array == NULL)
		return;
	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node != NULL)
		{
			next = node->next;
			free(node->key);
			free(node->value);
			free(node);
			node = next;
		}
	}
	free(ht->array);
	ht->array = NULL;
	ht->shead = ht->stail = NULL;
	ht->size = 0;
	free(ht);
}
