#include "shell.h"
/**
 * handle_lines - command lines entered by pipe are executed
 * @buf: name of program
 * @buf_len: length of buffer
 * @args: Argument 1
 * @env_args: Enviroment arguments
 * Return: 0
*/
void handle_lines(char *buf, int buf_len, char **args, char **env_args)
{
	if (buf_len == EOF)
	{
		printf("salida EOF\n");
		write(STDOUT_FILENO, "\n", 1);
		if (buf != NULL)
		{
			free_memory(1, buf);
			buf = NULL;
		}
		if (args != NULL)
		{
			free_memory(2, args);
			args = NULL;
		}
		if (env_args != NULL)
		{
			free_memory(2, env_args);
			env_args = NULL;
		}
		exit(0);
	}
}


