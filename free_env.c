#include "shell.h"
/**
 * free_env - free parsed PATH diretories and user's arguments
 * @env_args: parsed environment directories
 * @args: parsed user's commands
 * Return: NULL
 */

void free_env(char **env_args, char **args)
{
	if (env_args != NULL)
	{
		free_memory(2, env_args);
	}
	free_memory(2, args);
}
