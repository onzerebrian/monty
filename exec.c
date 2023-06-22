#include "monty.h"
/**
 * funct - functions to be executed
 * @token: code
 * Return: returns 0
 */

void (*funct(char *token))(stack_t **stack, unsigned int line_number)
{
	instruction_t code[] = {
		{"push", __push},
		{"pall", __pall},
		{"pint", __pint},
		{"pop", __pop},
		{"swap", __swap},
		{"add", __add},
		{"nop", __nop},
		{"err", err},
		{NULL, NULL}};
	int i = 0, m;

	while (i < 19)
	{
		m = strcmp(token, code[i].opcode);
		if (m == 0)
		{
		return (code[i].f);
		}
		i++;
	}
	return (code[8].f);
}

