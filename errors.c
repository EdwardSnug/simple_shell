#include "shell.h"
/**
 * p_error - writes error messages
 * @args: command to execute
 * Return: 0
 */
void p_error(char **args)
{
	int loop = 1;
	char *hsh_home = "";
	char *error_message = malloc(sizeof(char) * 255);
	char *looper = NULL;

	looper = int_to_str(loop);
	error_message = _strdup(hsh_home);
	error_message = my_str_concat(error_message, ":");
	error_message = my_str_concat(error_message, looper);
	error_message = my_str_concat(error_message, ":");
	error_message = my_str_concat(error_message, args[0]);
	perror(error_message);
	free(error_message);
}
/**
 * handle_bad_cmd - writes error messages
 * @args: command to exeute
 * @buf: command to execute
 * Return: 0
 */
void handle_bad_cmd(char **args, char *buf)
{
	write(STDOUT_FILENO, "command not found\n", 18);
	free_memory(1, buf);
	buf = NULL;
	free_memory(2, args);
	args = NULL;
}

