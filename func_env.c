#include "shell.h"
/**
 * print_env_vars - environment variables are printed here.
 * Return: 0
 */
int print_env_vars(void)
{
	int count = 0, length = 0;

	while (environ[count] != NULL)
	{
		length = str_length(environ[count]);
		write(STDOUT_FILENO, environ[count], length);
		write(STDOUT_FILENO, "\n", 1);
		count++;
	}

	return (0);
}
