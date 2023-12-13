#include "shell.h"
/**
 * constr_cmd_args - command lines entered by pipe are executed
 * @buf: name of command
 * Return: 0
*/
char **constr_cmd_args(char *buf)
{
	int size = 0;
	char **command = NULL;

	size = count_delim_str(buf);
	command = tokenize(buf, size);
	if (command == NULL)
	{
		free_memory(2, command);
		command = NULL;
	}

	return (command);
}


