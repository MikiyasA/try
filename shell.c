#include "shell.h"

/**
 * main - Function creates child process for handling
 * input commands to the parrent process.
 *
 * Return: 0
 */
int main(void)
{
	int id, err_num = 0;
	char *buffer, **argv;
	node_t *head;
	size_t size = 1;

	path_l_list(&head);
	buffer = malloc(size);
	while (1)
	{
		printf("#cisfun$ ");
		if (getline(&buffer, &size, stdin) == EOF)
		{
			printf("\nexit\n");
			return (0);
		}

		argv = populate_argv(buffer, " ", head);

		id = fork();
		if (id != 0)
			wait(NULL);
		else
			break;
	}
	if (id == 0)
		err_num = execve(argv[0], argv, NULL);
	if (err_num == -1)
		perror(strerror(errno));
	return (0);
}
