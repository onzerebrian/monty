#include "monty.h"
/**
 * __swap - function
 * @stack: pointer
 * @line_number: line
 */
void __swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack && (*stack)->next)
	{
		temp = (*stack)->next;
		if (temp == NULL)
		{
			exit(0);
		}
		(*stack)->next = temp->next;
		(*stack)->prev = temp;
		temp->next = *stack;
		temp->prev = NULL;
		*stack = temp;
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free(global.content);
		fclose(global.file);
		f_st(stack);
		exit(EXIT_FAILURE);
	}
}
