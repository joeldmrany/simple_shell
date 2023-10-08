#include "shell.h"

/**
 **_memset - make the memory have exactly account of bytes
 *
 *@s: memory pointer
 *@b: *s byte
 *@n: the bytes amount
 *
 *Return: a memory pointer to something
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int a;

	for (a = 0; a < n; a++)
		s[a] = b;
	return (s);
}

/**
 * ffree - it frees it
 * @pp: a string
 */
void ffree(char **pp)
{
	char **t = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(t);
}

/**
 * _realloc - it reallocs any memory
 * @ptr: a pointer to it
 * @old_size: size of bytes
 * @new_size: new block size
 *
 * Return: the pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *s;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	s = malloc(new_size);
	if (!s)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		s[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (s);
}

