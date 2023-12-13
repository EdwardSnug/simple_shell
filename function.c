#include <stdio.h>

/**
 * comp_str - compares two strings
 * @str1: string to be compared
 * @str2: string to compared
 * Return: 0
*/
int comp_str(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (0);

		str1++;
		str2++;
	}

	return (*str2 == '\0');
}

/**
 * str_contains - compares two strings
 * @str1: string to be compared
 * @str2: string to compared
 * Return: pointer
*/
char *str_contains(char *str1, char *str2)
{
	while (*str1 != '\0')
	{
		if ((*str1 == *str2) && comp_str(str1, str2))
			return (str1);
		str1++;
	}

	return (NULL);
}


/**
 * str_copy - copies the string pointed to by src
 *@dest: char
 *@src:_ char
 * Return: dest
 *
 */
char *str_copy(char *dest, char *src)
{
	int i = 0, j;

	while (src[i] != '\0')
	{
		i++;
	}
	for (j = 0; j <= i; j++)
	{
		dest[j] = src[j];
	}
	return (dest);
}


