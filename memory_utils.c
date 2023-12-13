#include "shell.h"
/**
* free_memory - frees memory
* @n: args
* Return: null
*/

void free_memory(int n, ...)
{
	int i = 0;
	char **ptr2 = NULL;
	char *ptr1 = NULL;
	va_list arg;

	va_start(arg, n);

	if (n == 1)
	{
		ptr1 = va_arg(arg, char *);
		free(ptr1);
	}

	if (n == 2)
	{
		ptr2 = va_arg(arg, char **);
		while (ptr2[i] != NULL)
		{
			free(ptr2[i]);
			i++;
		}
		free(ptr2);
	}
}

/**
* all_free - handles user's arguments and tokenized PATH directories memory
* @path_dirs: 1st double pointer to free
* @user_args: 2nd double pointer to free
* @s_ptr1: 1st single pointer to free
* @s_ptr2: 2nd double pointer to free
* Return: 0
*/

void all_free(char **path_dirs, char **user_args, char *s_ptr1, char *s_ptr2)
{

	if (path_dirs != NULL)
	{
		free_memory(2, path_dirs);
		path_dirs = NULL;
	}
	if (user_args != NULL)
	{
		free_memory(2, user_args);
		user_args = NULL;
	}
	if (s_ptr1 != NULL)
	{
		free(s_ptr1);
		s_ptr1 = NULL;
	}
	if (s_ptr2 != NULL)
	{
		free(s_ptr2);
		s_ptr2 = NULL;
	}
}


