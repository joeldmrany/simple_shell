#include "shell.h"

/**
 * sigintHandler - you can't use ctrl c
 * @sig_num: signal number
 *
 * Return: (void)
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
/**
 * read_buf - the buffer
 *
 * @info: parameter structure
 *
 * @buf: buffering it
 * @i: size of it
 *
 * Return: the char
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t r = 0;

	if (*i)
		return (0);
	r = read(info->readfd, buf, READ_BUF_SIZE);
	if (r >= 0)
		*i = r;
	return (r);
}

