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
/**
 *_atoi - make a string treated as number
 *@s: a converted string
 *Return: the number or 0 if it isn't number
 */

int _atoi(char *s)
{
	int a, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (a = 0;  s[a] != '\0' && flag != 2; a++)
	{
		if (s[a] == '-')
			sign *= -1;

		if (s[a] >= '0' && s[a] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[a] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

