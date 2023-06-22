#include "monty.h"

/**
 * main - start of the execution cycle
 * @argc: argument count
 * argv: argument vector
 * Return: returns 0 on success
 */
char **argv = NULL;

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
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		line[strcspn(line, "\n")] = '\0';

		if (strlen(line) == 0 || line[0] == '#')
			continue;
		char *opcode = strtok(line, " \t\n");
		char *argv = strtok(NULL, " \t\n");

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
	free(line);
	free_stack(stack);
	fclose(file);
	return (0);
}
