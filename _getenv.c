#include "shell.h"

/**
 * _getenv - Function gets the value of an environmental variable
 * @name: Name of the environmental variable
 *
 * Return: Value of the variable, NULL if not found
 */
char *_getenv(const char *name)
{
	int i = 0;
	char *token;

	while (*(environ + i))
	{
		token = strtok(*(environ + i), "=");
		if (!strcmp(name, token))
		{
			token = strtok(NULL, "=");
			return (strdup(token));
		}
		i++;
	}
	return (NULL);
}
