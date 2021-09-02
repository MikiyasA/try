#include "shell.h"

/**
 * check_in_path - Function searches PATH for the existence
 * of @av0 program
 * @buffer: First delimited string passed on command line
 * Return: 0 if it exists, -1 otherwise
 */
ssize_t check_in_path(char **buffer)
{
	struct stat st;
	char **av;
	node_t *head = NULL, *traverser;

	av = populate_argv(*buffer, " ");

	if (stat(av[0], &st) == 0)
	{
		free_av(av);
		return (0);
	}
	path_l_list(&head, av[0]);
	traverser = head;
	while (traverser != NULL)
	{
		if (stat(traverser->str, &st) == 0)
		{
			make_new_buffer(buffer, traverser->str);
			free_av(av), free_list(head);
			return (0);
		}
		traverser = traverser->next;
	}
	free_av(av), free_list(head);
	return (-1);
}

/**
 * free_av - Function frees argument vector passed to it
 * (NOTE: - first index is directly copied from strtok so freeing it
 * frees the whole 2D array)
 * @av: Pointer to a 2D vector
 *
 * Return: void
 */
void free_av(char **av)
{
	free(av[0]), free(av);
}

/**
 * free_list - Function frees a linked list passed to it
 * @head: Pointer to first Node in the linked list
 *
 * Return: void
 */
void free_list(node_t *head)
{
	while (head != NULL)
	{
		node_t *temp = head;

		head = head->next;
		free(temp->str), free(temp);
	}
}
