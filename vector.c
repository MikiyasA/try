#include "shell.h"

/**
 * populate_argv - Function populates an argument vector with
 * sent delimited string.
 * @buffer: @delim delimited string
 * @delim: Delimiter of @buffer
 *
 * Return: Populated argument vector
 */
char **populate_argv(char *buffer, char *delim)
{
	int i = 1;
	char *duplicate, *token, **argv;

	duplicate = strdup(buffer);
	token = strtok(duplicate, delim);
	while (1)
	{
		token = strtok(NULL, delim), i++;
		if (token == NULL || !strcmp(token, "\n"))
			break;
	}
	free(duplicate);
	argv = malloc(sizeof(char *) * i);
	duplicate = strdup(buffer), i = 1;
	token = strtok(duplicate, delim);
	argv[0] = strdup(token);
	if (argv[0][strlen(argv[0]) - 1] == '\n')
		strtok(argv[0], "\n");
	while (1)
	{
		token = strtok(NULL, delim);
		if (token == NULL || !strcmp(token, "\n"))
		{
			argv[i] = NULL;
			break;
		}
		argv[i] = strdup(token), i++;
	}
	if (i >= 2)
		strtok(argv[i - 1], "\n");
	free(duplicate);
	return (argv);
}
