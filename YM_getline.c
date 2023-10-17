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

