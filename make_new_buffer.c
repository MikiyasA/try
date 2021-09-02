#include "shell.h"

/**
 * make_new_buffer - Function creates a new and modified buffer
 * having an absolute path as its first tokenizable word
 * @buffer: Address the address where user input is stored in
 * @abs_path: Concatenated path where the executable (old buffer's
 * first word)
 *
 * Return: void
 */
void make_new_buffer(char **buffer, char *abs_path)
{
	size_t i = 0, mem_size;
	char *args;

        while (*(*buffer + i) != ' ' && *(*buffer + i) != '\n')
                i++;

        args = strdup(*buffer + i);

        free(*buffer);
        
        mem_size = strlen(abs_path) + strlen(args) + 1;

        *buffer = malloc(mem_size), memset(*buffer, 0, mem_size);

        strcat(*buffer, abs_path);

        strcat(*buffer, args);

        free(args);
}
