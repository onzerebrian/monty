#include "monty.h"

/**
 * check_int - function
 * @num: value
 * Return: 0 on success
 */
int check_int(char *num)
{
	int i = 0;

	if (!num)
	{
		return (1);
	}

	if (num[i] == 45)
		i++;
	while (num[i])
	{
		if (num[i] < 48 || num[i] > 57)
			return (-1);
		i++;
	}
	return (0);
}
