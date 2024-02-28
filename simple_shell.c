#include "shell.h"

/**
* main - print prompt
* @argc: arg count
* @argv: argv command
* Return: always 0
*/

int main(int argc, __attribute__((unused)) char *argv[])
{
char *ch = NULL;
size_t buff_size = 0;
ssize_t file_access = 0;
(void)argc;
while (1)
{
if (isatty(STDIN_FILENO) == 1)
write(1, "$ ", 2);
file_access = getline(&ch, &buff_size, stdin);
if (file_access == -1)
{
if (isatty(STDIN_FILENO) == 1)
write(1, "\n", 1);
break;
}
if (ch[file_access - 1]  == '\n')
ch[file_access - 1]  = '\0';
if (*ch == '\0')
continue;
if (dir_read(ch, file_access) == 2)
break;
}
free(ch);
ch = NULL;
return (0);
}
/**
* dir_read - handles command line and tokenizes it
* @str: string
* @file_access: getline input
* Return: 0
*/

int dir_read(char *str, size_t __attribute__((unused))file_access)
{
char *tok = NULL;
char *dir_arr[100];
int x;
if (str_cmp(str, "exit") == 0)
return (2);
if (str_cmp(str, "env") == 0)
return (0);
tok = strtok(str, " "), x = 0;
while (tok)
{
dir_arr[x++] = tok;
tok = strtok(NULL, " ");
}
dir_arr[x] = NULL;
return (call_comm(dir_arr));
}

/**
* directive_not_found - prints not found
* @dir: a string
* Return: nothing
*/
void directive_not_found(char *dir)
{
write(2, dir, str_len(dir));
write(2, "./shell: No such file or directory\n", 36);
}

/**
* call_comm - call
* @dir_arr: a string provided by the stdin
* Return: 0
*/

int call_comm(char *dir_arr[])
{
char *exe_path = NULL;
char *dir = NULL;
pid_t is_child;
int status;
dir = dir_arr[0];
exe_path = shell_explorer(dir);
if (exe_path == NULL)
{
directive_not_found(dir);
return (3);
}
is_child = fork();
if (is_child < 0)
{
perror("Error:");
return (-1);
}
if (is_child > 0)
wait(&status);
else if (is_child == 0)
{
(execve(exe_path, dir_arr, environ));
perror("Error:");
exit(1);
}
free(exe_path);
return (0);
}
