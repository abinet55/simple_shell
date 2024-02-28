#include "shell.h"

/**
* *str_cat- concatenates two strings
* @dest: Char input
* @src: Char input
* Return: always 0
*/

char *str_cat(char *dest, char *src)
{
int y = 0;
int length = str_len(dest);
while (src[y] != '\0')
{
dest[length] = src[y];
length++;
y++;
}
dest[length] = '\0';
return (dest);
}

/**
* str_cmp - compares two strings
* @s1: first string
* @s2: second string
* Return: 0 or 1
*/

int str_cmp(char *s1, char *s2)
{
while (*s1 == *s2)
{
if (*s1 == '\0')
{
return (0);
}
s1++;
s2++;
}
return (*s1 - *s2);
}
char *str_cpy(char *dest, char *src)
{
int length, x;
length = str_len(src);
for (x = 0; x < length; x++)
{
dest[x] = src[x];
}
dest[x] = '\0';
return (dest);
}

/**
* str_len- returns the length of string
* @ch: Charchter
* Return: Always 0.
*/

int str_len(char *ch)
{
int y = 0;
while (ch[y] != '\0')
{
y++;
}
return (y);
}

/**
* *in_str_cp - copie input string
* @string: input string
* Return: pointer
*/

char *in_str_cp(char *string)
{
char *duplicate;
unsigned int x = 0, length = 0;
if (string == NULL)
return (NULL);
while (string[length])
length++;
duplicate = malloc(sizeof(char) * (length + 1));
if (duplicate == NULL)
return (NULL);
while ((duplicate[x] = string[x]) != '\0')
x++;
return (duplicate);
}

