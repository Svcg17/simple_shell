#include "header.h"

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
