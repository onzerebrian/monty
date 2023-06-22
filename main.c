#include "monty.h"

/**
 * main - start of the execution cycle
 * Return: returns 0 on success
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	} file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
	line_number++;
	char *opcode = strtok(line, " \t\n");
	char *arg = strtok(NULL, " \t\n");

	if (opcode != NULL)
	{
		int i;
		instruction_t instructions[] = {
			{"push", push},
			{"pall", pall},
			{"pint", pint},
			{"pop", pop},
			{"swap", swap},
			{"add", add},
			{"nop", nop},
			{"sub", sub},
			{"div", _div},
			{NULL, NULL}
		};

		for (i = 0; instructions[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				/* Execute the opcode function */
				instructions[i].f(&stack, line_number);
				break;
			}
		}
		if (instructions[i].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
	}
	fclose(file);
	free(line);
	return (0);
}
