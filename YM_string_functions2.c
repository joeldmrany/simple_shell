#include "shell.h"

/**
 * _putchar - get the char from input to output
 * @c: printed char
 *
 * Return: 1 or -1 
 */
int _putchar(char c)
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
void _puts(char *str)
{
	int b = 0;

	if (!str)
		return;
	while (str[b] != '\0')
	{
		_putchar(str[b]);
		b++;
	}
}

