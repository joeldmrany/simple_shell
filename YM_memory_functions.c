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

