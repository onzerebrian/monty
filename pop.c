#include "monty.h"
/**
 * __pop - function
 * @stack: pointer
 * @line_number: line
 */
void __pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free(global.content);
		fclose(global.file);
		f_st(stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next)
	{
		*stack = temp->next;
		(*stack)->prev = NULL;
		free(temp);
	}
	else
		{
		f_st(stack);
		}
}
