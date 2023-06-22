#include "monty.h"

/**
 * __pint - function
 * @stack: pointer
 * @line_number: line
 */
void __pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (temp == NULL)
	{
		free(global.content);
		fclose(global.file);
		f_st(stack);
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", temp->n);
}
