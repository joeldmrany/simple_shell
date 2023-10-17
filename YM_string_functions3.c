#include "shell.h"

/**
 **_strchr - get the character place in the string
 *@s: the string s
 *@c: the char c
 *Return: the string or NULL
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

