#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number where the push operation is performed.
 */
void push(stack_t **stack, unsigned int line_number)
{

	if (argv[1] == NULL || is_number(argv[1]) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_entire_arr(argv);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	insert_node_at_index(stack, 0, atoi(argv[1]));
}

/**
 * pall - Prints all the elements in the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number where the pall operation is performed.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	line_number = line_number;

	print_stack(*stack);

}
