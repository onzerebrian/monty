#include "monty.h"

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success
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
		/* Tokenize the line to separate opcode and arguments */
		char *opcode = strtok(line, " \t\n");
		char *arg = strtok(NULL, " \t\n");

		exec_instruction(opcode, &stack, line_number);
		/* Free the argument tokens */
		free(opcode);
		free(arg);
	}
	free(line);
	free_stack(stack);
	fclose(file);

	return (0);
}

