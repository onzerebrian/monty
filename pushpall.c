#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number where the push operation is performed.
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \t\n");

	if (arg == NULL || !is_number(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(arg);
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
		new_node->next = *stack;
	}
	*stack = new_node;
}
/**
 * pall - Prints all the elements in the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number where the pall operation is performed.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
