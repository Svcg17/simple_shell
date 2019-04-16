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

int execerror(char *buff, char **bigb, int counter, char *arg)
{
	char *str1 = NULL;
	char *str2 = NULL;
	char *str3 = NULL;
	char *str4 = NULL;
	char *str5 = NULL;
	int length;
	char *c = NULL;

	c = _itoa(counter);

	if (isatty(0))
		str1 = str_concat("mango ", ": ");
	else
		str1 = str_concat(arg, ": ");
	str2 = str_concat(str1, c);
	free(str1);
	str3 = str_concat(str2, ": ");
	free(str2);
        str4 = str_concat(str3, buff);
	free(str3);
        str5 = str_concat(str4, ": not found\n");
	free(str4);

	length = _strlen(str5);
	write(1, str5, length);
	free(c);
	free(str5);

	free_some(buff, bigb);
	return (-1);
}

int child_fail(char *buff, char **bigb)
{
	free_some(buff, bigb);
	perror("Error: ");
	return (1);
}
