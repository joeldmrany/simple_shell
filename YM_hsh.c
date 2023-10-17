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
/**
 * find_builtin - buiting finder
 *
 * @info: a value of return
 *
 * Return: 0 or 1 or -2 or -1
 */
int find_builtin(info_t *info)
{
	int s, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (s = 0; builtintbl[s].type; s++)
		if (_strcmp(info->argv[0], builtintbl[s].type) == 0)
		{
			info->line_count++;
			built_in_ret = builtintbl[s].func(info);
			break;
		}
	return (built_in_ret);
}

/**
 * find_cmd - command finder
 * @info: returning value of parameter
 *
 * Return: (void)
 */
void find_cmd(info_t *info)
{
	char *path = NULL;
	int b, k;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (b = 0, k = 0; info->arg[b]; b++)
		if (!is_delim(info->arg[b], " \t\n"))
			k++;
	if (!k)
		return;

	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
			|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}

