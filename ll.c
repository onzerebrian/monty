#include "monty.h"


/**
 * ll - length of the line
 * @line: line to read
 * Return: line
 */
int ll(char *line)
{
	unsigned int count = 0;

	while (line[count])
	{
		count++;
	}
	return (count);
}
