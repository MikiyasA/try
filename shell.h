#ifndef _SHELL_H_
#define _SHELL_H_

/**
 * struct Node - Singly linked list
 * @str: String - (malloc'ed string)
 * @next: Points to the next node
 *
 * Description: Singly linked list node structure
 * for PATH directories
 */
typedef struct Node
{
	char *str;
	struct Node *next;
} node_t;

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <errno.h>
#include <sys/stat.h>

extern char **environ;

char **populate_argv(char *, char *);
void make_new_buffer(char **, char *);
void path_l_list(node_t **, char *);
char *_getenv(const char *name);
ssize_t  check_in_path(char **);
ssize_t check_empty(char **);
void free_list(node_t *);
void free_av(char **);

#endif /* _SHELL_H_ */
