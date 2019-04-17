#include "header.h"
/**
 * _strcmp - compares two strings
 * @s1: one of the strings to compare
 * @s2: the other string to compare
 * Return: difference in length
 */

int _strcmp(char *s1, const char *s2)
{
	int i;

	for (i = 0; (s1[i] == s2[i]) && (s1[i] || s2[i]); i++)
		;
	return (s1[i] - s2[i]);
}

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to return
 * Return: the length of the string
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return (i);
}




/**
 * _memset - fills memory with a constant byte
 * @s: pointer to memory area to fill
 * @b: the number of bytes to fill
 * @n: constant byte
 * Return: a pointer to the memory area @s
 */


char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}

	return (s);
}



/**
 * _strcat - concatenates two strings
 * @dest: the string @src is added to
 * @src: the string to be appended
 * Return: pointer to the resulting string @dest
 */
char *_strcat(char *dest, char *src)
{
	int len1; /* string length for src */
	int len2; /* string length for dest */
	int i;

	len1 = 0;
	len2 = 0;

	while (src[len1] != '\0')
		len1++;

	while (dest[len2] != '\0')
		len2++;

	for (i = 0; i <= len1; i++)
	{
		dest[len2] = src[i];
		len2++;
	}
	return (dest);
}
/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: The string to copy
 * Return: a pointer to the duplicated string, NULL if insufficient memory
 * or if @str is NULL
 */
char *_strdup(char *str)
{
	char *ar;
	unsigned int i = 0;
	unsigned int j = 0;

	if (str == NULL)
		return (NULL);
	while (str[i])
		i++;
	ar = malloc(sizeof(char) * (i + 1));
	if (ar == NULL)
		return (NULL);
	while (str[j])
	{
		ar[j] = str[j];
		j++;
	}
	ar[j] = 0;
	return (ar);
}
