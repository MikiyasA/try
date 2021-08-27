#include "shell.h"

/**
 * check_empty - Function checks if buffer is empty
 * (i.e it can't be interpreted as a command.)
 * @buffer: Input buffer from user
 *
 * Return: 0 if not empty, -1 otherwise
 */
ssize_t check_empty(char *buffer)
{
	while (*buffer)
	{
		if (*buffer == 32 || *buffer == '\n')
			buffer++;
		else
			return (-1);
	}
	return (0);
}
