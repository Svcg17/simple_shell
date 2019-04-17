#include "header.h"
/**
 * exitt - exits the shell when 'exit' is typed
 * Return: -1
 */
int exitt(void)
{
	return (-1);
}

/**
 * printenv - prints out the environment
 * Return: 1
 */

int printenv(void)
{
	int i;
	char *cpy;

	for (i = 0; environ[i]; i++)
	{
		cpy = _strdup(environ[i]);
		_puts(cpy);
		free(cpy);
	}
	return (1);
}
/**
 * getbuiltfunc - Checks if user inputted a built-in command
 * @s: user input
 * Return: 0
 */
int getbuiltfunc(char *s)
{
	built ins[] = {
		{"env", printenv},
		{"exit", exitt},
		{NULL, NULL}
	};
	int j;

	if (s != NULL)
	{
		for (j = 0; ins[j].str; j++)
		{
			if (_strcmp(s, ins[j].str) == 0)
				return (ins[j].f());
		}
	}
	return (0);
}
