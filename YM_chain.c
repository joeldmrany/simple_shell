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
/**
 * is_chain - buffer checker
 * @info: parameter structure
 *
 * @buf: letter of buffer
 *
 * @p: the string position like p
 *
 * Return: 1 or 0
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[j] == ';') /* found the final */
	{
		buf[j] = 0; /* make ; NULL*/
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = j;
	return (1);
}
/**
 * check_chain - the chain of checker
 * @info: parameter structure
 * @buf: char buffer
 * @p: string like it
 * @i: buffering it
 * @len: the length of power
 *
 * Return: (void)
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
 * replace_vars - replace it by another
 * @info: parameter structure
 *
 * Return: 1 or 0
 */
int replace_vars(info_t *info)
{
	int d = 0;
	list_t *node;

	for (d = 0; info->argv[d]; d++)
	{
		if (info->argv[d][0] != '$' || !info->argv[d][1])
			continue;

		if (!_strcmp(info->argv[d], "$?"))
		{
			replace_string(&(info->argv[d]),
				_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[d], "$$"))
		{
			replace_string(&(info->argv[d]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[d][1], '=');
		if (node)
		{
			replace_string(&(info->argv[d]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[d], _strdup(""));

	}
	return (0);
}

