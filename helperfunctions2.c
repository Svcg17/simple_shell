#include "header.h"

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
 * rev_string - Reverses a string
 *
 * @s: The string to reverse
 *
 * Return: nothing
 */

void rev_string(char *s)
{
	int i;
	int len;
	char newStr;

	i = 0;
	len = _strlen(s) - 1;

	while (len >= i)
	{
		newStr = s[len]; /*newStr == n*/
		s[len] = s[i]; /*s[len] == H*/
		s[i] = newStr; /*s[i] == n*/
		len--;
		i++;
	}
}

int no_of_digits(int num)
{
	int digit_count = 0;

	while(num > 0)
	{
		digit_count++;
		num /= 10;
	}

	return digit_count;
}


char *i_to_a(int num)
{
	char *str;
	int digit_count = 0;

	if(num < 0)
	{
		num = -1*num;
		digit_count++;
	}

	digit_count += no_of_digits(num);
	str = (char *)malloc(sizeof(char)*(digit_count+1));

	str[digit_count] = '\0';

	while(num > 0)
	{
		str[digit_count-1] = num%10 + '0';
		num = num/10;
		digit_count--;
	}

	if(digit_count == 1)
		str[0] = '-';

	return str;
}
