#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>


/**
 * struct list - linked list for environmental variables
 * @var: Sttring
 * @next: points to next node
 */
typedef struct list
{
	char *var;
	struct list *next;

} list_t;

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int t_strlen(char *str, int pos, char delm);
char *my_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
int my_strcmp(char *s1, char *s2);
size_t get_line(char **str);
char *ignore_space(char *str);

#endif
