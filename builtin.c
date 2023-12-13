#include "shell.h"
/**
* find_builtin_cmd -  finds if a command is builtin.
* @input: user's command
* Return: Pointer or NULL.
*/
int (*find_builtin_cmd(char *input))()
{
	int count = 0, stru_size = 0;

	builtin_cmd_struct builtins[] = {
		{"exit", exit_shell},
		{"env", print_env_vars},
	};

	stru_size = (sizeof(builtins) / sizeof(builtin_cmd_struct));
	if (input != NULL)
	{
		while (count < stru_size)
		{
			if (strcomp(builtins[count].cmd_name, input) == 0)
				return (builtins[count].cmd_fxn);
			count++;
		}
	}
	return (NULL);
}


