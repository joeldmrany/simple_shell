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
/**
 **_strncpy - string copier
 *@dest: a destination
 *@src: a source
 *@n: the copied structure
 *Return: string concatenated
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}


