#include "header.h"
/**
 *free_all - free all memory allocated
 * @buff: buffer with user input
 * @bigb: array of strings of user input
 * @cmd: full path of user input
 * Return: nothing
 */
void free_all(char *buff, char **bigb, char *cmd)
{
	free(buff);
	free(cmd);
	free(bigb);
}

/**
 * free_some - free buffer and bigb
 * @buff: buffer with user input
 * @bigb: array of strings of user input
 * Return: nothing
 */
void free_some(char *buff, char **bigb)
{
	free(buff);
	free(bigb);
}

/**
 * free_parent - frees allocated memory in parent process
 * @buff: command from input
 * @bigb: parsed command
 * @cmd: concatenated command
 */
void free_parent(char *buff, char **bigb, char *cmd)
{
/*for commands like /bin/ls*/
	if (bigb[0][0] == '/')
		free_some(buff, bigb);
	else
		free_all(buff, bigb, cmd);
}

/**
 * execerror - Handles the error message and free() when execute fails
 * @buff: the user inputted string
 * @bigb: the string of arrays holding the input command and flags
 * @counter: integer counter to display for error
 * @arg: Executable file name for non-interactive mode
 * Return: -1
 */
int execerror(char *buff, char **bigb, int counter, char *arg)
{
	char *str1 = NULL;
	char *str2 = NULL;
	char *str3 = NULL;
	char *str4 = NULL;
	char *str5 = NULL;
	int length;
	char *c = NULL;
/*convert counter to a string*/
	c = _itoa(counter);
/*if inside a terminal error starts with shell name (mango)*/
	if (isatty(0))
		str1 = str_concat("mango", ": ");
/*else error starts with the executable name (./mango)*/
	else
		str1 = str_concat(arg, ": ");
/*concatenate each string with a different variable and free*/
	str2 = str_concat(str1, c);
	free(str1);
	str3 = str_concat(str2, ": ");
	free(str2);
	str4 = str_concat(str3, buff);
	free(str3);
	str5 = str_concat(str4, ": not found\n");
	free(str4);
/*find length of total concatenated string*/
	length = _strlen(str5);
/*write string to stdout*/
	write(1, str5, length);
/*free from itoa*/
	free(c);
/*free final concatenated string*/
	free(str5);
	free_some(buff, bigb);
	exit(127);
}

/**
 * child_fail - handles free() and error if child fails
 * @buff: the user inputted string
 * @bigb: string of arrays holding inputted command and any flags
 * Return: 1
 */

int child_fail(char *buff, char **bigb)
{
	free_some(buff, bigb);
	perror("Error: ");
	exit(1);
}
