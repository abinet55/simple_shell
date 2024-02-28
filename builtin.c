#include "shell.h"

/**
 * enviro_print - prints enviroment
 * Return: 0
 */
int enviro_print(void)
{
	char *ch = environ[0];
	int j = 0;
	
	while (ch)
	{
		write(1, ch, str_len(ch));
		write(1, "\n", 1);
		ch = environ[++j];
	}
	return (0);
}

/**
 * cmp_str - compares count charchaters
 * from two strings and returns an integer based on the result.
 * @s1: first string
 * @s2: second string
 * @n: count of the comparison
 * Return: 0 or 1
 */
int cmp_str(char *s1, char *s2, int n)
{
	char ch1, ch2;
	while (n--)
	{
		ch1 = *s1++;
		ch2 = *s2++;
		if (ch1 == '\0' || ch1 != ch2)
			return (ch1 > ch2 ? 1 : (ch1 < ch2 ? -1 : 0));
	}
	return (0);
}

/**
 * env_get - prints environment like getenv
 * @variable: environment variable
 * Return: 0
 */
char *env_get(char *variable)
{
	int j = 0;
	for (j = 0; environ[j]; j++)
	{
		if (cmp_str(environ[j], variable, str_len(variable)) == 0)
			return (&environ[j][str_len(variable)]);
	}
	return (NULL);
}
