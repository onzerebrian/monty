#include "monty.h"
/**
 * __add - function
 * @stack: pointer
 * @line_number: line
 */
void __add(stack_t **stack, unsigned int line_number)
{
	stack_t *t1;
	stack_t *t2;
	int sum = 0;

	if (*stack && (*stack)->next)
	{
		t2 = (*stack)->next;
		sum = (*stack)->n + t2->n;
		t1 = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(t1);
		(*stack)->n = sum;
	}
	else
	{
	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	free(global.content);
	fclose(global.file);
	f_st(stack);
	exit(EXIT_FAILURE);
	}
}
