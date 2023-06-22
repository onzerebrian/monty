#include "monty.h"

/**
 * is_number - checks if a string is a number
 * @s: the string
 *
 * Return: 1 if it is a number, 0 otherwise
 */
int is_number(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (i == 0 && s[i] == '-')
			continue;
		if (s[i] < 48 || s[i] > 57)
			return (0);
	}
	return (1);
}

