#include "shell.h"

/**
 * replace_alias - replaces aliases
 * @info: parameter structure
 *
 * Return: 1 or 0
 */
int replace_alias(info_t *info)
{
	int c;
	list_t *node;
	char *p;

	for (c = 0; c < 10; c++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * replace_string - replace the string by another one
 * @old: old address
 * @new: new one
 *
 * Return: 1 or 0
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}

