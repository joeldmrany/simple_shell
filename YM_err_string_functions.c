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

