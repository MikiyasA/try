#include "shell.h"

/**
 * check_in_path - Function searches PATH for the existence
 * of @av0 program
 * @av0: First space delimited string passed on command line
 * @head: Pointer to PATH linked list
 * Return: Absolute path of @av0, NULL if @av0 is not found
 */
char *check_in_path(char *av0, node_t *head)
{
	struct stat st;
	char *str = NULL;

	while (head != NULL)
	{
		str = strcat(strcat(head->str, "/"), av0);
		if (stat(str, &st) == 0)
			break;
		head = head->next;
	}
	return (str);
}
