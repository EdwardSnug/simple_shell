#include "shell.h"

/**
 * strn_comp - Compares 2 strings with n size
 * @str1: Given String 1
 * @str2: Given String 2
 * @n: Size to character compare
 * Return: 0
*/
int strn_comp(char *str1, char *str2, size_t n)
{
	while (n && *str1 && (*str1 == *str2))
	{
		++str1;
		++str2;
		--n;
	}
	if (n == 0)
	{
		return (0);
	}
	else
	{
		return (*(unsigned char *)str1 - *(unsigned char *)str2);
	}
}

/**
 * str_length - returns length of a given string
 * @str: Given string
 * Return: elements number
*/
int str_length(char *str)
{
	int length;

	for (length = 0; str[length] != '\0'; length++)
		;
	return (length);
}

/**
 * _strdup - Duplicates a string
 * @str: given string
 * Return: Copy of string
*/
char *_strdup(char *str)
{
	char *ptr;
	int i, length;

	length = 0;
	if (str == NULL)
		return (NULL);
	length = str_length(str);
	ptr = malloc(sizeof(char) * (length + 1));
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i < length; i++)
		ptr[i] = str[i];
	ptr[i] = '\0';
	return (ptr);
}

/**
 * strcomp - Compares 2 given  strings
 * @str1: Str1 String
 * @str2: Str2 String
 * Return: 0 if both are equals or ascii diff
*/
int strcomp(char *str1, char *str2)
{
	int diff, index;

	diff = index = 0;
	if (str1 == NULL || str2 == NULL)
		return (-1);
	while (str1[index] != '\0' && str2[index] != '\0')
	{
		diff = str1[index] - str2[index];
		if (diff != 0)
			break;
		index++;
	}
	return (diff);
}

/**
 *my_str_concat - concatenates two strings.
 *@destination: destination string
 *@src: source string
 *Return: dest
 */
char *my_str_concat(char *destination, char *src)
{
	int n, i;

	for (n = 0; destination[n] != '\0'; n++)
	{
	}
	for (i = 0; src[i] != '\0'; i++)
	{
		destination[n + i] = src[i];
	}
	destination[n + i] = '\0';

	return (destination);
}


