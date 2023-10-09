#include "shell.h"



/**
 *_isalpha - checks if character is alpha
 *@c: an input character
 *Return: returns 1 or 0
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * is_delim - it checks the code
 * @c: a checkered char
 * @delim: a strint
 * Return: return 1, else 0
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * interactive - if the mode is interactive return true (1) value
 * @info: address structure
 * Return: when the mode is interactive return 1, else 0
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

