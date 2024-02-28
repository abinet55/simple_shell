#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

int print_env(void);
char *in_str_cp(char *string);
int dir_read(char *s, size_t __attribute__((unused))file_stream);
char *shell_explorer(char *dir);
char *str_cat(char *dest, char *src);
int str_cmp(char *s1, char *s2);
char *str_cpy(char *dest, char *src);
int str_len(char *ch);
void directive_not_found(char *dir);
int call_comm(char *dir_arr[]);
char *env_get(char *variable);
int cmp_str(char *s1, char *s2, int n);

#endif
