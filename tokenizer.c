#include "shell.h"
/**
 * count_delim_str - commands and options entered by user are counted
 * @buf: given command
 * Return: argument number
*/
int count_delim_str(char *buf)
{
	int count = 0;
	char *delimiter = " =:'\n''\t'";
	int i = 0;
	int j = 0;

	while (buf[i] != '\0')
	{
		for (j = 0; delimiter[j] != '\0'; j++)
		{
			if (buf[i] == delimiter[j])
			{
				count++;
				break;
			}
		}
		i++;
	}
	return (count + 1);
}

/**
 * tokenize - Splits a given string
 * @buf: Given string
 * @num_tokens: elements number
 * Return: Parsed string
*/

char **tokenize(char *buf, int num_tokens)
{
	int counter = 0;
	char *token = NULL;
	char *delimiter = " :'\n''\t'";
	char **token_count = malloc(sizeof(char *) * num_tokens);

	if (token_count == NULL)
	{
		return (NULL);
	}
	token = strtok(buf, delimiter);
	while (token != NULL)
	{
		token_count[counter] = _strdup(token);
		if (token_count[counter] == NULL)
		{
			free_memory(2, token_count);
			return (NULL);
		}
		token = strtok(NULL, delimiter);
		counter++;
	}
	token_count[counter] = NULL;
	return (token_count);
}


