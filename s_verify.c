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
