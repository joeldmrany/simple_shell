#include "shell.h"

/**
 * bfree - make a free for a pointer an NULL
 * @pointer: pointer to free something
 *
 * Return: 0 or 1
 */
int bfree(void **pointer)
{
	if (pointer && *pointer)
	{
		free(*pointer);
		*pointer = NULL;
		return (1);
	}
	return (0);
}

