#include "monty.h"

/**
 * reverse - reverse string s in place
 * @s: the string to be reversed
 *
 * Return: void
 */
void reverse(char s[])
{
	int i, j;
	char c;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

/**
 * itoa - convert n to characters in s
 * @n: the number to be converted
 *
 * Return: the converted string
 */
char *itoa(int n)
{
	char s[1024];
	int i, sign;

	sign = n;
	if (sign < 0)  /* record sign */
		n = -n;          /* make n positive */
	i = 0;
	do {       /* generate digits in reverse order */
		s[i++] = n % 10 + '0';   /* get next digit */
	} while ((n /= 10) > 0);     /* delete it */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);

	return (strdup(s));
}
