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
/**
 * list_to_strings - gets the string array
 * @head: first null pointer
 *
 * Return: string array
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}
/**
 * print_list - get a list of all elements
 * @h: pointer for it's node
 *
 * Return: list size
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_put(convert_number(h->num, 10, 0));
		_putschar(':');
		_putschar(' ');
		_put(h->str ? h->str : "(nil)");
		_put("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * list_len - get the list of DC
 * @h: first null pointer
 *
 * Return: list size
 */
size_t list_len(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - gets the prefix
 * @node: list node
 * @prefix: matched string
 * @c: the char after to it's string
 *
 * Return: node matched, NULL
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}


