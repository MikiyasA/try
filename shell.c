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
	size_t size = 120;
	char **argv, *buffer = malloc(size);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("[%s@%s]$ ", _getenv("USER"), "Linux");
		if (getline(&buffer, &size, stdin) == EOF)
		{
                        free(buffer);
			if (isatty(STDIN_FILENO))
				printf("\nexit\n");
			return (err_num);
		} else if (check_empty(&buffer) == 0)
			continue;
		if (check_in_path(&buffer) == 0)
			id = fork();
		else
		{
			fprintf(stderr, "%s: %s\n", av[ac - ac], "No such file or directory");
			continue;
		}
		if (id == 0)
			break;
		wait(NULL); 
	}
	argv = populate_argv(buffer, " ");
	setenv("SHELL", "hsh", 1);
	err_num = execve(argv[0], argv, environ);
	free(buffer), free(argv[0]), free(argv[1]), free(argv);
	if (err_num == -1)
		fprintf(stderr, "%s: %s\n", av[ac - ac], strerror(errno));
	return (0);
}
