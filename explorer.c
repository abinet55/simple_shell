#include "shell.h"

/**
* *shell_explorer - explore path
* @dir: directives
* Return: new path
*/
char *shell_explorer(char *dir)
{
char *path = in_str_cp(env_get("PATH"));
int i = 0, j = 0;
char *path_tok = strtok(path, ":");
char *path_arr[100];
char *s2 = dir;
char *new_path = NULL;
struct stat buff;
new_path = malloc(sizeof(char) * 100);
if (env_get("PATH")[0] == ':')
if (stat(dir, &buff) == 0)
return (in_str_cp(dir));
while (path_tok != NULL)
{
path_arr[i++] = path_tok;
path_tok = strtok(NULL, ":");
}
path_arr[i] = NULL;
for (j = 0; path_arr[j]; j++)
{
str_cpy(new_path, path_arr[j]);
str_cat(new_path, "/");
str_cat(new_path, s2);
str_cat(new_path, "\0");
if (stat(new_path, &buff) == 0)
{
free(path);
return (new_path);
}
else
new_path[0] = 0;
}
free(path);
free(new_path);
if (stat(dir, &buff) == 0)
return (in_str_cp(dir));
return (NULL);
}
