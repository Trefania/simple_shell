#include "shell.h"

int _isdigit(int c);
int _atoi(char *s);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, const char *const src, int start);
/**
 * _strstart - Checks if s1 has s2 at its beginning
 * @s1: The string
 * @s2: Sun string of s1 to be checked
 * Return: 1 if true, 0 otherwise
 */

int _strstart(char *s1, char *s2)
{
	char *sub;
	int len, i, match = 0;

	if (s1 == NULL || s2 == NULL)
		return (0);

	len = _strlen(s2);
	sub = malloc(sizeof(char) * len + 1);
	if (sub == NULL)
		return (0);

	for (i = 0; i < len && s1[i] != '\0'; i++)
		sub[i] = s1[i];
	sub[i] = '\0';
	if (_strcmp(sub, s2) == 0)
		match = 1;
	free(sub);
	return (match);
}

/**
 * _atoi - Convert a string to integer.
 * @s: char array string
 * Description: Number in the string
 * You need to take into account all
 * If there are no numbers in the string, return 0.
 * Not allowed to hard-code special values.
 * Return: first integer found in string
*/

int _atoi(char *s)
{
	int negative = 0;
	int start = 0;
	int foundigit = 0;
	int i;
	int n = 0;
	int steps = 0;
	int c;

	for (i = 0; s[i] != '\0'; i++)
	{
		c = s[i];
		if (c == '-' && start != 1)
		{
			if (negative == 1)
				negative = 0;
			else
				negative = 1;
		}

		if (_isdigit(c) != 1 && foundigit == 1)
			break;
		if (foundigit != 1 && _isdigit(c) == 1)
		{
			foundigit = 1;
			start = 1;
			steps = 1;
		}
		if (foundigit)
		{
			n = (n * steps) + (int)(c - 48);
			steps = 10;
		}
	}
	if (negative == 1)
		return (n * -1);
	else
		return (n);
}

/**
 * _strlen - returns the length of a string
 * @str: string to evaluate
 * Return: the length of the string
*/
int _strlen(char *str)
{
	int len, i;

	if (str == NULL)
		return (0);

	for (i = 0, len = 0; str[i] != '\0'; i++)
		len++;

	return (len);
}

/**
 * _strcpy -  copies a string.
 * @src: the string to be copied from
 * @dest: the string to be copied to
 * Return: A pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 *  _strdup - Duplicates a string
 * @str: The string
 * Return: The duplicate
 */

char *_strdup(char *str)
{
	char *dup;

	if (str == NULL)
		return (NULL);

	dup = malloc(sizeof(char) * _strlen(str) + 1);
	if (dup == NULL)
		return (NULL);
	dup = _strcpy(dup, str);
	return (dup);
}
