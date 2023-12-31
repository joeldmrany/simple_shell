#include "shell.h"

/**
 * _putchar - get the char from input to output
 * @c: printed char
 *
 * Return: 1 or -1
 */
int _putschar(char c)
{
	static int a;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(1, buf, a);
		a = 0;
	}
	if (c != BUF_FLUSH)
		buf[a++] = c;
	return (1);
}
/**
 * _strcpy - string copier
 * @dest: a destination
 * @src: a source
 *
 * Return: destination pointer
 */
char *_strcpy(char *dest, char *src)
{
	int b = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[b])
	{
		dest[b] = src[b];
		b++;
	}
	dest[b] = 0;
	return (dest);
}
/**
 *_puts - get the string from input to output
 *@str: the string
 *
 * Return: (void)
 */
void _put(char *str)
{
	int b = 0;

	if (!str)
		return;
	while (str[b] != '\0')
	{
		_putschar(str[b]);
		b++;
	}
}
/**
 * _strdup - string duplicater
 * @str: duplicated string
 *
 * Return: duplicated string pointer
 */
char *_strdup(const char *str)
{
	int count = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		count++;
	ret = malloc(sizeof(char) * (count + 1));
	if (!ret)
		return (NULL);
	for (count++; count--;)
		ret[count] = *--str;
	return (ret);
}

