#include "shell.h"

/**
 * path_l_list - Function creates linked list of directories
 * listed in PATH
 * @head: Pointer to pointer of a linked list
 *
 * Return: void
 */
void path_l_list(node_t **head)
{
	char *token, *path;
	node_t *new;

	path = _getenv("PATH");
	token = strtok(path, ":");

	while (token != NULL)
	{
		new = malloc(sizeof(node_t));

		new->str = strdup(token);
		new->next = *head;

		*head = new;
		token = strtok(NULL, ":");
	}
}
