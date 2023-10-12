#include "shell.h"

/**
 * get_node_index - the index is ok
 * @head: headed node
 * @node: node pointer
 *
 * Return: index's node
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}

