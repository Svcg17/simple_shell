#include "header.h"
/**
 * main - a simple shell
 *
 * Return: 0
 */
int main(void)
{
	int status, line;
        int counter = 0, builtfunc_ret = 0;
        char *buff = NULL, *cmd = NULL;
        char **bigb = NULL;
        size_t size = 0;
        pid_t child_pd;

	signal(SIGINT, SIG_IGN);
	while (1)
	{
		buff = NULL, bigb = NULL, cmd = NULL;
		counter++;
		if (isatty(0))
			printf("mango$ ");
		line = getline(&buff, &size, stdin);
		if (line == -1)
			return (checkline(buff));
		bigb = getinput(buff);
		if (bigb[0] == NULL)
		{
			free_some(buff, bigb);
			continue;
		}
		builtfunc_ret = getbuiltfunc(bigb[0]);
		if (builtfunc_ret == -1)
			break;
		cmd = get_env(bigb[0]);
		child_pd = fork();
		if (child_pd == -1)
			return (child_fail(buff, bigb));
		if (child_pd == 0)
		{
			if (cmd == NULL)
				cmd = "";
			if (execve(cmd, bigb, NULL) == -1)
				return(execerror(buff, bigb));
		}
		else
		{
			wait(&status);
			free_parent(buff, bigb, cmd);
		}
	}
	free_some(buff, bigb);
	return (0);
}
