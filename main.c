#include "shell.h"
/**
 * main - Shell entry point
 * @ac: Arguments counter
 * @av: Argument vector
 * Return: 0
*/

int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{

	int is_interactive = 1;
	int status_code = 0;


	status_code = status_code + 0;

	is_interactive = isatty(STDIN_FILENO);
	if (is_interactive == 0)
	{
		exec_piped_cmd(av);
	}
	else
	{

		Interactive_shell(av);
	}
	return (0);
}
