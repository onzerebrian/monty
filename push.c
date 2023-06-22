#include "monty.h"

/**
 * __push - push function
 * @stack: head pointer
 * @line_number: line (current)
 */
void __push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	s_v(stack, line_number);
	if (global.token)
	{
		new = malloc(sizeof(stack_t));
		if (new == NULL)
		{
			fputs("Error: malloc failed\n", stderr);
			exit(EXIT_FAILURE);
		}
		new->n = global.num, new->next = NULL;
		new->prev = NULL;
		if (*stack)
		{
			if (global.flag == 1)
			{
				new->next = *stack;
				(*stack)->prev = new;
				*stack = new;
			}
			else
			{
				while ((*stack)->next)
					*stack = (*stack)->next;
				(*stack)->next = new, new->prev = *stack;
				while ((*stack)->prev)
					*stack = (*stack)->prev;
			}
		}
		else
			*stack = new;
	}
	else
	{
		free(global.content), fclose(global.file);
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		f_st(stack);
		exit(EXIT_FAILURE);
	}
}
