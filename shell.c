#include "shell.h"

/**
 * main - Function creates child process for handling
 * input commands to the parrent process.
 * @ac: Number of cmd arguments
 * @av: Cmd argument vector
 *
 * Return: 0
 */
int main(int ac, char *av[])
{
	int id, err_num = 0;
	char *buffer, **argv;
	node_t *head;
	size_t size = 1;

	path_l_list(&head);
	buffer = malloc(size);
	while (1)
	{
		printf("$ ");
		if (getline(&buffer, &size, stdin) == EOF)
			return (0);

		argv = populate_argv(buffer, " ");

		id = fork();
		if (id != 0)
			wait(NULL);
		else
			break;
	}
	if (id == 0)
		err_num = execve(argv[0], argv, NULL);
	if (err_num == -1)
		fprintf(stderr, "%s: %s\n", av[ac - ac], strerror(errno));
	return (0);
}
