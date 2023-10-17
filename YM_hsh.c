#include "shell.h"

/**
 * fork_cmd - having it
 *
 * @info: information parameters
 *
 * Return: (void)
 */
void fork_cmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		/* TODO: ERRORING */
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: SEMI ERROR */
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}
/**
 * hsh - mains loop
 *
 * @info: parameter return value
 * @av: vectorial argument
 *
 * Return: 1 or 0
 */
int hsh(info_t *info, char **av)
{
	ssize_t r = 0;
	int retur = 0;

	while (r != -1 && retur != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		r = get_input(info);
		if (r != -1)
		{
			set_info(info, av);
			retur = find_builtin(info);
			if (retur == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (retur == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (retur);
}

