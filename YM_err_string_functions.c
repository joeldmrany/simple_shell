#include "shell.h"

/**
 * _putfd - make the character more to the output
 * @c: char
 * @fd: the fd
 *
 * Return: 1 or -1 or 0
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 *_eputs - output the string

 * @str: outputted string
 *
 * Return: void
 */
void _eputs(char *str)
{
	int a = 0;

	if (!str)
		return;
	while (str[a] != '\0')
	{
		_eputchar(str[a]);
		a++;
	}
}
/**
 *_putsfd - output the string
 * @str: outputted sentence
 * @fd: a fd
 *
 * Return: any number
 */
int _putsfd(char *str, int fd)
{
	int a = 0;

	if (!str)
		return (0);
	while (*str)
	{
		a += _putfd(*str++, fd);
	}
	return (a);
}


