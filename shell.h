#ifndef _SHELL_H_
#define _SHELL_H_

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
char *_getenv(const char *name);
char *check_in_path(char *, node_t *);
void path_l_list(node_t **);

#endif /* _SHELL_H_ */
