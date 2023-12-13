#include "shell.h"
/**
 * Interactive_shell - Creates a loop that execute command
 * lines entered by user
 * @av: argument from main
 * Return: The exit status of shell
*/
int Interactive_shell(char **av __attribute__((unused)))
{
	size_t n;
	char *buf = NULL;
	char **env_args = NULL;
	char **command = NULL;
	char *full_command = NULL;
	int (*cmd_fxn)() = NULL;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		getline(&buf, &n, stdin);
		handle_lines(buf, 0, command, env_args);
		if (buf[0] == 10 || buf[0] == 9)
			continue;
		command = constr_cmd_args(buf);
		if (command == NULL)
			continue;
		cmd_fxn = find_builtin_cmd(*command);
		if (cmd_fxn)
		{
			if (cmd_fxn == exit_shell)
				all_free(command, env_args, buf, NULL);
			cmd_fxn();
			all_free(command, NULL, NULL, NULL);
			continue;
		}
		env_args = get_env_path_dir();
		if (env_args == NULL)
			return (-1);
		full_command = insert_path_to_cmd(command, env_args);
		if (full_command == NULL)
			write(STDOUT_FILENO, "command NOT found\n", 18);
		else
			execcmd(full_command, command);
		free_memory(1, buf), buf = NULL;
		free_memory(2, command), command = NULL;
		free_memory(2, env_args), env_args = NULL;
	}
	return (0);
}


