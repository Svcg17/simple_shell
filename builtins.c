#include "header.h"

/**
 * exitshell - exits the shell when 'exit' is typed
 * Return: -1
 */

int exitt(void)
{
	return (-1);
}

int printenv(void)
{
	int i;
	for (i = 0; environ[i]; i ++)
	{
		printf("%s\n", environ[i]);
	}
	return (1);
}
