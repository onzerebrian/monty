#include "monty.h"
/**
 * s_v - function
 * @stack: pointer
 * @line_number: line
 */
void s_v(stack_t **stack, unsigned int line_number)
{
	if (check_int(global.token) == 0)
		global.num = atoi(global.token);
	else
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		f_st(stack);
		free(global.content);
		fclose(global.file);
		exit(EXIT_FAILURE);
	}
}
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
