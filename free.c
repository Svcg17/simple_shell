#include "header.h"
/**
 *free_all - free all memory allocated
 * @buff: buffer with user input
 * @bigb: array of strings of user input
 * @cmd: full path of user input
 */
void free_all(char *buff, char **bigb, char *cmd)
{
	free(buff);
	free(cmd);
	free(bigb);
}
/**
 *free_some - free buffer and bigb
 * @buff: buffer with user input
 * @bigb: array of strings of user input
 */
void free_some(char *buff, char **bigb)
{
	free(buff);
	free(bigb);
}

void free_parent(char *buff, char **bigb, char *cmd)
{
	if ((bigb[0][0] == '/'))
	{
		free_some(buff, bigb);
	}
/*badboy*/
	else
	{
		free_all(buff, bigb, cmd);
	}
}

int execerror(char *buff, char **bigb)
{
	perror("Errror");
	free_some(buff, bigb);
	return (-1);
}

int child_fail(char *buff, char **bigb)
{
	free_some(buff, bigb);
	perror("Error: ");
	return (1);
}
