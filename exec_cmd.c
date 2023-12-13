#include "shell.h"
/**
 * execcmd - Executes user's given command
 * @cmd: command
 * @args: command arguments
 * Return: 0
 */
int execcmd(char *cmd, char **args)
{
	int status;
	pid_t pid;
	int err_code = 0;

	pid = fork();
	if (!pid)
	{
		if (execve(cmd, args, environ) == -1)
		{
			free_memory(1, cmd);
			cmd = NULL;
			err_code = errno;
			p_error(args);
			exit(err_code);
		}
		else
		{
			free_memory(1, cmd);
			cmd = NULL;
			exit(err_code);
		}
	}
	else
		wait(&status);

	free_memory(1, cmd);
	cmd = NULL;
	err_code = 0;
	return (err_code);
}

