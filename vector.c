#include "shell.h"

/**
 * populate_argv - Function populates an argument vector with
 * sent delimited string.
 * @buffer: @delim delimited string
 * @delim: Delimiter of @buffer
 * @head: Pointer to first node of PATH linked list
 *
 * Return: Populated argument vector
 */
char **populate_argv(char *buffer, char *delim, node_t *head)
{
	int i = 1;
	char *duplicate, *token, *path, **argv;

	duplicate = strdup(buffer);
	token = strtok(duplicate, delim);
	while (1)
	{
		token = strtok(NULL, delim), i++;
		if (token == NULL || !strcmp(token, "\n"))
			break;
	}
	argv = malloc(sizeof(char *) * i);
	duplicate = strdup(buffer), i = 1;
	token = strtok(duplicate, delim);
	if (path)
		argv[0] = path;
	else
		argv[0] = token;
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
	return (argv);
}
