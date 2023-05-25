#ifndef _MAIN_
#define _MAIN_
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <limits.h>
#include <sys/stat.h>

#define BUFFERSIZE 1024
#define TOK_BUFFERSIZE 128
#define TOK_DELIM " \t\r\n\a"

extern char **environ;


/**
 * struct lists - struct lists
 * @av: String pointer
 * @input: String
 * @args: String
 * @status: Integer
 * @counter: Integer
 * @_environ: String
 * @pid: String
 */
typedef struct lists
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} lists_shell;

/**
 * struct sep_list_s - single linked list
 * @separator: char
 * @next: next node
 * Description: single linked list
 */
typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;

/**
 * struct list_s - single linked list
 * @line: Char
 * @next: next node
 * Description: single linked list
 */
typedef struct list_s
{
	char *line;
	struct list_s *next;
} line_list;

/**
 * struct var_list - single linked list
 * @len_var: Integer
 * @val: String
 * @len_val: Integer
 * @next: next node
 * Description: single linked list
 */
typedef struct var_list
{
	int len_var;
	char *val;
	int len_val;
	struct var_list *next;
} r_var;

/**
 * struct builtins_s - Builtin struct
 * @name: String
 * @f: function pointer
 */
typedef struct builtins_s
{
	char *name;
	int (*f)(lists_shell *listssh);
} builtin_t;

sep_list *add_sep_node_end(sep_list **head, char sep);
void free_sep_list(sep_list **head);
line_list *add_line_node_end(line_list **head, char *line);
void free_line_list(line_list **head);

r_var *add_rvar_node(r_var **head, int lvar, char *var, int lval);
void free_rvar_list(r_var **head);

char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);

void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);

char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);

void rev_string(char *s);

int repeated_char(char *input, int i);
int error_sep_op(char *input, int i, char last);
int first_char(char *input, int *i);
void print_syntax_error(lists_shell *listssh, char *input, int i, int bool);
int check_syntax_error(lists_shell *listssh, char *input);

char *without_comment(char *in);
void shell_loop(lists_shell *listssh);

char *read_line(int *i_eof);

char *swap_char(char *input, int bool);
void add_nodes(sep_list **head_s, line_list **head_l, char *input);
void go_next(sep_list **list_s, line_list **list_l, lists_shell *listssh);
int split_commands(lists_shell *listssh, char *input);
char **split_line(char *input);

void check_env(r_var **h, char *in, lists_shell *lists);
int check_vars(r_var **h, char *in, char *st, lists_shell *lists);
char *replaced_input(r_var **head, char *input, char *new_input, int nlen);
char *rep_var(char *input, lists_shell *listssh);

void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);

int exec_line(lists_shell *listssh);

int is_cdir(char *path, int *i);
char *_which(char *cmd, char **_environ);
int is_executable(lists_shell *listssh);
int check_error_cmd(char *dir, lists_shell *listssh);
int cmd_exec(lists_shell *listssh);

char *_getenv(const char *name, char **_environ);
int _env(lists_shell *listssh);

char *copy_info(char *name, char *value);
void set_env(char *name, char *value, lists_shell *listssh);
int _setenv(lists_shell *listssh);
int _unsetenv(lists_shell *listssh);

void cd_dot(lists_shell *listssh);
void cd_to(lists_shell *listssh);
void cd_previous(lists_shell *listssh);
void cd_to_home(lists_shell *listssh);

int cd_shell(lists_shell *listssh);

int (*get_builtin(char *cmd))(lists_shell *listssh);

int exit_shell(lists_shell *listssh);

int get_len(int n);
char *aux_itoa(int n);
int _atoi(char *s);

char *strcat_cd(lists_shell *, char *, char *, char *);
char *error_get_cd(lists_shell *listssh);
char *error_not_found(lists_shell *listssh);
char *error_exit_shell(lists_shell *listssh);

char *error_get_alias(char **args);
char *error_env(lists_shell *listssh);
char *error_syntax(char **args);
char *error_permission(char **args);
char *error_path_126(lists_shell *listssh);

int get_error(lists_shell *listssh, int eval);

void get_sigint(int sig);

void aux_help_env(void);
void aux_help_setenv(void);
void aux_help_unsetenv(void);
void aux_help_general(void);
void aux_help_exit(void);

void aux_help(void);
void aux_help_alias(void);
void aux_help_cd(void);

int get_help(lists_shell *listssh);

#endif
