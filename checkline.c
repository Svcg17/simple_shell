#include "header.h"
/**
 * checkline - function for when line is -1
 * @buff: integer from getline
 * Return: zero in success
 */
int checkline(char *buff)
{
	if (isatty(0))
		_putchar('\n');

	free(buff);
	exit(0);
}
