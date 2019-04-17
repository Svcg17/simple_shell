#include "header.h"
/**
 * _puts - prints a string and a newline.
 * @str: pointer to a character.
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}
