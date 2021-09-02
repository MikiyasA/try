#include "shell.h"

/**
 * check_empty - Function checks if buffer is empty
 * (i.e it can't be interpreted as a command.)
 * @buffer: Input buffer from user
 *
 * Return: 0 if not empty, -1 otherwise
 */
ssize_t check_empty(char **buffer)
{
	int i = 0;
	char *non_empty_str = NULL;

	while (*(*buffer + i))
	{
		if (*(*buffer + i) == 32 || *(*buffer + i) == '\n')
			i++;
		else
		{
			non_empty_str = strdup(*buffer + i);
			free(*buffer);
			*buffer = non_empty_str;
			return (-1);
		}
	}
	return (0);
}
