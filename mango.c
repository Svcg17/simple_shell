#include "header.h"

/**
 * main - a simple shell
 *
 * Return: 0
 */

int main(void)
{
	int status;

	size_t size = 0;

	char *buff = NULL;
	char **bigb = NULL;
	char *cmd = NULL;
	pid_t child_pd;

	int line;

/*	struct stat st; */

	int counter = 0;
	int builtfunc_ret = 0;

	while (1)
	{
		/* bigb = malloc(sizeof(char *) * 1024);*/
		/* buff = malloc(sizeof(char) * 1024); */
		buff = NULL;
		bigb = NULL;
		cmd = NULL;
		counter++;
		if (isatty(fileno(stdin)))
			printf("mango$ ");

		line = getline(&buff, &size, stdin);
		if (line == -1)
		{
			printf("\n");

			free(buff);
			return (0);
		}
/*
		else if (buff[0] == '\n')
			continue;
*/
		bigb = getinput(buff);
		if (bigb[0] == '\0')
		{
			free(buff);
			free(bigb);
			continue;
		}
		builtfunc_ret = getbuiltfunc(bigb[0]);
		if (builtfunc_ret == -1)
		{
			break;
		}
		cmd = get_env(bigb[0]);
		child_pd = fork();
		if (child_pd == -1)
		{
			free(buff);
			free(bigb);
			perror("Error: ");
			return (1);
		}
		if (child_pd == 0)
		{
			if (cmd == NULL)
			{
				cmd = "";
			}
			if (execve(cmd, bigb, NULL) == -1)
			{
				printf("mango: %d: %s: not found\n", counter, buff);
				free(buff);
				free(bigb);
/*
  not sure what this does, keep an eye if there is a problem, do tests
                                free(cmd);
*/
				return (-1);
			}
		}
		else
		{
			wait(&status);
			if (bigb[0][0] == '/')
			{
				free(buff);
				free(bigb);
			}
			else
			{
				free(buff);
				free(cmd);
				free(bigb);
			}
		}
	}
	free(buff);
	free(bigb);
	return (0);
}
