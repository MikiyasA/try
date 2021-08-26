#include "shell.h"

/**
 * _getenv - Function gets the value of an environmental variable
 * @name: Name of the environmental variable
 *
 * Return: Value of the variable, NULL if not found
 */
char *_getenv(const char *name)
{
	char *token, **local_env;

	local_env = environ;

	while (*local_env)
	{
		token = strtok(*environ, "=");
		if (!strcmp(name, token))
		{
			token = strtok(NULL, "=");
			return (strdup(token));
		}
		local_env++;
	}
	return (NULL);
}
