#include "shell.h"

/**
 * _getenv - Function gets the value of an environmental variable
 * @name: Name of the environmental variable
 *
 * Return: Value of the variable, NULL if not found
 */
char *_getenv(const char *name)
{
	int i, j, k;
	
        k = 0;
        while (*(environ + k))
        {
                i = 0, j = 0;

                while (*(*(environ + k) + i) != '=')
                        i++;
                while (j < i)
                {
                        if (*(name + j) == *(*(environ + k) + j))
                                j++;
                        else
                                break;
                }
                if (j == i)
                        return (*(environ + k) + i + 1);
                k++;
        }
	return (NULL);
}
