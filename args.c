#include "shell.h"

/**
 * avsize - Count all arguments parsed
 * @args: Args List
 *
 * Return: int
 */
int avsize(char **args)
{
	int size, i;

	if (args == NULL)
		return (0);

	for (i = 0, size = 0; args[i] != NULL; i++)
		++size;
	return (size);
}
