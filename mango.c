#include "header.h"
/**
 * main - a simple shell
 * @argc: argument counter ((unused))
 * @argv: argument vector
 * Return: 0
 */
int main(int argc __attribute__((unused)), char **argv)
{
	int line;
	int counter = 0, builtfunc_ret = 0;
	char *buff = NULL, *cmd = NULL;
	char **bigb = NULL;
	size_t size = 0;
	struct stat st;

	signal(SIGINT, SIG_IGN);
	while (1)
	{
		buff = NULL, bigb = NULL, cmd = NULL;
		counter++;
		if (isatty(0))
		{
			_putchar('$');
			_putchar(' ');
		}
		line = getline(&buff, &size, stdin);
		if (line == -1)
			return (checkline(buff));
		bigb = getinput(buff);
		if (bigb[0] == NULL)
		{
			free_some(buff, bigb);
			continue;
		}
		if (stat(bigb[0], &st) == 0 && bigb[0][0] == '/')
			cmd = bigb[0];
		else
		{
			builtfunc_ret = getbuiltfunc(bigb[0]);
			if (builtfunc_ret == -1)
				break;
			cmd = get_env(bigb[0]);
		}
		child_split(buff, bigb, cmd, argv, counter);
	}
	free_some(buff, bigb);
	return (0);
}

/**
 * child_split - runs the child process
 * @buff: user input
 * @bigb: array of strings that hold user input as well any flags
 * @cmd: concatenated string of user input
 * @argv: argument vector, used to hold the executable of this shell
 * @counter: a count of how many times the loop runs
 */
void child_split(char *buff, char **bigb, char *cmd, char **argv, int counter)
{
	pid_t child_pd;
	int status;

	child_pd = fork();
	if (child_pd == -1)
		child_fail(buff, bigb);
	if (child_pd == 0)
	{
		/*if getenv() returns NULL*/
		if (cmd == NULL)
			cmd = "";
		if (execve(cmd, bigb, environ) == -1)
			execerror(buff, bigb, counter, argv[0]);
	}
	else
	{
		wait(&status);
		free_parent(buff, bigb, cmd);
	}
}
