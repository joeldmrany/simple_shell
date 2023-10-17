#include "shell.h"

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

