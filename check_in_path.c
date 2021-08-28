#include "shell.h"

/**
 * check_in_path - Function searches PATH for the existence
 * of @av0 program
 * @buffer: First delimited string passed on command line
 * Return: 0 if it exists, -1 otherwise
 */
ssize_t check_in_path(char *buffer)
{
	struct stat st;
	char **av = populate_argv(buffer, " ");

	if (stat(av[0], &st) == 0)
	{
		free(av[0]), free(av);
		return (0);
	}
	free(av[0]), free(av);
	return (-1);
}
