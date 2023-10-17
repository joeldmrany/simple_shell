#include "shell.h"

/**
 * _strcmp - perform string cmp
 * @s1: stranger one
 * @s2: stranger two
 *
 * Return: - or + or 0
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * _strcat - make two strings concatenates
 * @dest: buffering destination
 * @src: buffering source
 *
 * Return: buffering destination pointer
 */
char *_strcat(char *dest, char *src)
{
	char *raet = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (raet);
}

/**
 * starts_with - haystack checker
 * @haystack: searcher haystack
 * @needle: string finder
 *
 * Return: NULL or thing else
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}


