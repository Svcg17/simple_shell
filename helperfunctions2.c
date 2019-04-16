#include "header.h"

/**
 * _strcmp - compares two strings
 * @s1: one of the strings to compare
 * @s2: the other string to compare
 * Return: difference in length
 */

int _strncmp(char *s1, const char *s2, int n)
{
        int i;

        for (i = 0; (s1[i] == s2[i]) && (s1[i] || s2[i]) && i < n; i++)
                ;
        return (i != n);
}

/**
 * str_concat - concatenates two string
 *
 * @s1: the first string
 * @s2: the string to add to @s1
 *
 * Return: a pointer that points to a newly allocated space which
 * contains the contents of @s1, followed by the contents of @s2,
 * and null terminated. Should return NULL on failure
 */

char *str_concat(char *s1, char *s2)
{
	char *s3;
	unsigned int s1len = 0;
	unsigned int s2len = 0;
	unsigned int s3len;
	unsigned int i = 0;
	unsigned int j = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[s1len])
		s1len++;
	while (s2[s2len])
		s2len++;

	s3len = s1len + s2len;

	s3 = malloc(sizeof(char) * s3len + 1);
	if (s3 == NULL)
		return (NULL);

	while (i < s1len)
	{
		s3[i] = s1[i];
		i++;
	}

	while (i <= s3len)
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	return (s3);
}
/**
 * digit_number - counts the number of digits in an integer
 * @num: the number to count through
 * Return: the number of digits @num has
 */
int _getcount(int num)
{
	int counter = 0;
	unsigned int m = num;

	while(m > 0)
	{
		m = m / 10;
		counter++;
	}
	return (counter);
}

/**
 * _itoa - Converts an integer to a string
 * @num: the number to convert
 * Return: the new string
 */

char *_itoa(int num)
{
	char *s;
	int i =  _getcount(num);

	s = malloc(sizeof(char)*(i + 1));
	s[i] = '\0';
	while (num > 0)
	{
		s[i - 1] = num % 10 + '0';
		num = num / 10;
		i--;
	}
	return (s);
}
