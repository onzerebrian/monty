#include "monty.h"

/**
 * nl - function
 * @line: pointer
 * Return: line
 */
char nl(char *line)
{
	int len = ll(line);

	line[len - 1] = '\0';
	return (*line);
}
