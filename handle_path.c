#include "shell.h"

/**
 * find_path_env - handle the PATH variable from environment
 * Return: PATH variables
*/
char *find_path_env()
{
	char *path = NULL;
	int i = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strcomp(environ[i], "PATH") == 0)
		{
			path = malloc(sizeof(char *) * (str_length(environ[i])));
			if (path == NULL)
			{
				free_memory(1, path);
				exit(-1);
			}
			str_copy(path, environ[i]);
			break;
		}
	}
	return (path);
}

/**
 * replace_equals_with_colons - a character is changed to a given string
 * @str: given string
 * Return: NULL
*/

void replace_equals_with_colons(char *str)
{
	char **ptr_str = NULL;
	int i = 0;

	ptr_str = &str;

	while ((*(*ptr_str + i)) != '=')
	{
		(*(*ptr_str + i)) = ':';
		i++;
	}
	(*(*ptr_str + i)) = ':';
}

/**
 * insert_path_to_cmd - Inserts directory into a command
 * @args: given command
 * @path: tokenized path enviroment
 * Return: given command or full path command
*/

char *insert_path_to_cmd(char **args, char **path)
{
	char *cwd = getcwd(NULL, 0);
	struct stat verify;
	int counter = 0;
	int count_char = 0;
	char *tmp2 = NULL;
	char *dirpath = NULL;

	if (str_contains(args[0], "/") || str_contains(args[0], "."))
	{
		free_memory(1, cwd);
		cwd = NULL;
		tmp2 = malloc(sizeof(char *) * (str_length(args[0])));
		str_copy(tmp2, args[0]);
		return (tmp2);
	}
	else
	{
		while (path[counter] != NULL)
		{
			chdir(path[counter]);
			if (stat(args[0], &verify) == 0)
			{
				count_char = str_length(path[counter]) + 1 + str_length(args[0]);
				tmp2 = malloc(sizeof(char *) * count_char);
				str_copy(tmp2, path[counter]);
				my_str_concat(tmp2, "/"), my_str_concat(tmp2, args[0]);
				break;
			}
			counter++;
		}
	}
	chdir(cwd);
	if (tmp2 == NULL)
	{
		free_memory(1, cwd), cwd = NULL;
		free_memory(1, tmp2), tmp2 = NULL;
		return (dirpath);
	}
	dirpath = tmp2, free_memory(1, cwd), cwd = NULL;
	return (dirpath);
}

/**
 * get_env_path_dir - an array of pointers is created to the PATH directories
 * Return: Pointer to an array of parsed directories
*/

char **get_env_path_dir(void)
{
	char *tmp = NULL;
	int size_args = 0;
	char **env_args;

	tmp = find_path_env();
	replace_equals_with_colons(tmp);
	size_args = count_delim_str(tmp);
	env_args = tokenize(tmp, size_args);
	free_memory(1, tmp);
	tmp =  NULL;
	return (env_args);
}

/**
 * contains_only_spaces - an array of pointers created to the PATH directories
 * @buf: given string
 * Return: Pointer to an array of tokenized directories
*/

int contains_only_spaces(char *buf)
{
	int i = 0;

	while (buf[i] != '\0')
	{
		if (buf[i] != 32)
		{
			return (0);
		}
	i++;
	}
	return (1);
}


