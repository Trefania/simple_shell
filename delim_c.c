#include "shell.h"
/**
 * _comparedelim - Checks if a string includes some part of
 * delim
 * @str: the string
 * @delim: the delimiter
 * Return: index on success, otherwise -1
 */

int _comparedelim(char *str, char *delim)
{
	int found = 0, j, i;

	if (str == NULL || delim == NULL)
		return (-1);

	for (j = 0, i = 0; delim[j] != '\0'; j++)
	{
		if (str[i] == delim[j])
		{
			found = 1;
			++i;
		}

		if (str[i] != delim[j] && found == 1)
		{
			break;
			++i;
		}
	}
	if (found == 0)
		i = -1;
	return (i);
}
