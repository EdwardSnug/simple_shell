#ifndef SHELL_H
#define SHELL_H

#define GNU_SOURCE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdarg.h>

extern char **environ;
/**
 * struct builtin_cmd - Built in command structure
 * @cmd_name: command name
 * @cmd_fxn: pointer to a function
 */
typedef struct builtin_cmd
{
	char *cmd_name;
	int (*cmd_fxn)();
}builtin_cmd_struct;

int (*find_builtin_cmd(char *input))();
int num_len(int n);
char *int_to_str(int num);
void p_error(char **args);
void handle_bad_cmd(char **args, char *buf);
int execcmd(char *cmd, char **args);
int exit_shell(void);
void free_env(char **env_args, char **args);
int print_env_vars(void);
int comp_str(char *str1, char *str2);
char *str_contains(char *str1, char *str2);
char *str_copy(char *dest, char *src);
void handle_lines(char *buf, int buf_len, char **args, char **env_args);
char *find_path_env();
void replace_equals_with_colons(char *str);
char *insert_path_to_cmd(char **args, char **path);
char **get_env_path_dir(void);
int contains_only_spaces(char *buf);
int Interactive_shell(char **av __attribute__((unused)));
int main(int ac __attribute__((unused)), char **av __attribute__((unused)));
void free_memory(int n, ...);
void all_free(char **path_dirs, char **user_args, char *s_ptr1, char *s_ptr2);
char **constr_cmd_args(char *buf);
int exec_piped_cmd(char **av __attribute__((unused)));
int count_delim_str(char *buf);
char **tokenize(char *buf, int num_tokens);
int strn_comp(char *str1, char *str2, size_t n);
int str_length(char *str);
char *_strdup(char *str);
int strcomp(char *str1, char *str2);
char *my_str_concat(char *destination, char *src);
#endif
