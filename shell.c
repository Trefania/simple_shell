#include "shell.h"

/**
 * main - A simple shell program
 * @argc: The total args
 * @argv: List of args passed
 * @env: Arg list
 *
 * Return: 0
 */
int main(int argc, char **argv, char **env)
{
	char *str, *nocomments, *trimmed;
	int mode = 1;
	shell_var_t var = {0, 0, 0, NULL, NULL};

	var.pid = getpid();
	var.env = env;
	var.name = argv[0];
	while (mode)
	{
		str = NULL;
		if (argc > 1)
		{
			if (process_file(argv[1], &str) == 0)
				exit(0);
		}
		else
		{
			if ((int)prompt(&str, &mode) == -1)
				exit(0);
		}

		trimmed = _trim(str);
		nocomments = no_comment(trimmed);
		free(str);
		free(trimmed);
		str = nocomments;
		if (processLogical(str, &var) == 1)
			continue;
		else if (processCmdSp(str, &var) == 1)
			continue;
		else
			process_cmd(str, &var);
	}

	return (var.code);
}
