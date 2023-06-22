#include "monty.h"

/**
 * f_st - function
 * @stack: pointer
 */
void f_st(stack_t **stack)
{
	stack_t *del = *stack;

	while (*stack)
	{
		del = del->next;
		free(*stack);
		*stack = del;
	}
}
