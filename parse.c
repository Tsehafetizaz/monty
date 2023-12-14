#include "monty.h"
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
 * parse_line - Parses a line from Monty file and executes the opcode
 * @line: Line from the file
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file
 */
void parse_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcode, *arg;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_op},
		{NULL, NULL}
	};
	int i;

	opcode = strtok(line, " \n\t");
	if (opcode == NULL || opcode[0] == '#')
	{
		return;
	}

	arg = strtok(NULL, " \n\t");

	for (i = 0; ops[i].opcode; i++)
	{
		if (strcmp(ops[i].opcode, opcode) == 0)
		{
			ops[i].f(stack, line_number, arg);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

/**
 * parse_file - Opens and parses a Monty bytecode file
 * @file: File path
 * @stack: Double pointer to the top of the stack
 *
 * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on failure
 */
int parse_file(const char *file, stack_t **stack)
{
	FILE *fp;
	char *line = malloc(BUFFER_SIZE);
	size_t len = BUFFER_SIZE;
	unsigned int line_number = 0;

	if (line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (EXIT_FAILURE);
	}

	fp = fopen(file, "r");
if (fp == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", file);
free(line);
return (EXIT_FAILURE);
}

	while (fgets(line, len, fp) != NULL)
	{
		line_number++;
		parse_line(line, stack, line_number);
	}

	free(line);
	fclose(fp);
	return (EXIT_SUCCESS);
}
