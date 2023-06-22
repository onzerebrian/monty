#include "monty.h"

/**
 * err - function
 * @stack: pointer
 * @line_number: line
 */
void err(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, global.content);
	free(global.content);
	fclose(global.file);
	f_st(stack);
	exit(EXIT_FAILURE);
}
