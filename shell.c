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
	char *buffer, **argv, *token;
	node_t *head;
	size_t size = 1;

	path_l_list(&head);
	buffer = malloc(size);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		if (getline(&buffer, &size, stdin) == EOF)
			return (0);
		id = fork();
		if (id != 0)
			wait(NULL);
		else
			break;
	}
	argv = malloc(sizeof(char *) * 2);
	argv[0] = strtok(buffer, " ");
	argv[1] = NULL;
	token = strtok(NULL, " ");
	if (token != NULL && strcmp(token, "\n") != 0)
	{
		fprintf(stderr, "%s: %s\n", av[ac - ac], "No such file or directory");
		return (1);
	}
	if (token == NULL)
		strtok(argv[0], "\n");
	if (id == 0)
		err_num = execve(argv[0], argv, NULL);
	if (err_num == -1)
		fprintf(stderr, "%s: %s\n", av[ac - ac], strerror(errno));
	return (0);
}
