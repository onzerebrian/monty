#include "monty.h"

/**
 * get_opcode - finds the opcode
 * @s: the name of the opcode
 *
 * Return: a pointer to the handler function
 */
void (*get_opcode(char *s))(stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	int i = 0;

	while (instructions[i].opcode)
	{
		if (strcmp(s, instructions[i].opcode) == 0)
			return (instructions[i].f);
		i++;
	}
	return (NULL);
}

/**
 * exec_instruction - gets and executes the instruction
 * @s: the name of the instruction
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void exec_instruction(char *s, stack_t **stack, unsigned int line_number)
{
	void (*f)(stack_t **, unsigned int) = get_opcode(s);

	if (f)
		f(stack, line_number);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, s);
		free_entire_arr(argv);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}

