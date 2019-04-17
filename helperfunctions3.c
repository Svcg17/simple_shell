#include "header.h"
/**
 * _puts - prints a string and a newline.
 * @str: pointer to a character.
 */
void _puts(char *str)
{
	unsigned int i;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}
