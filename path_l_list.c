#include "shell.h"

/**
 * path_l_list - Function creates linked list of directories
 * listed in PATH
 * @head: Pointer to pointer of a linked list
 * @av0: First element of argument vector
 *
 * Return: void
 */
void path_l_list(node_t **head, char *av0)
{
	char *token, *paths;
	node_t *new;

	paths = strdup(_getenv("PATH"));
	token = strtok(paths, ":");

	while (token != NULL)
	{
		size_t mem_size = strlen(token) + strlen(av0) + 2;

		new = malloc(sizeof(node_t));

                mem_size = strlen(token) + strlen(av0) + 2;
                new->str = malloc(mem_size);
                memset(new->str, 0, mem_size);

                strcat(new->str, token);
                strcat(new->str, "/");
                strcat(new->str, av0);
                new->next = *head;

		*head = new;
		token = strtok(NULL, ":");
	}
	free(paths);
}
