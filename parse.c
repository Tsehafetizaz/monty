#include "monty.h"

/**
 * parse_line - Parses a line from Monty file and executes the opcode
 * @line: Line from the file
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file
 */
void parse_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcode;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},

		{NULL, NULL}
	};
	int i;

	opcode = strtok(line, " \n\t");
	if (opcode == NULL || opcode[0] == '#')
		return;

	for (i = 0; ops[i].opcode; i++)
	{
		if (strcmp(ops[i].opcode, opcode) == 0)
		{
			ops[i].f(stack, line_number);
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
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;

	fp = fopen(file, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		return (EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, fp)) != -1)
	{
		line_number++;
		parse_line(line, stack, line_number);
	}

	free(line);
	fclose(fp);
	return (EXIT_SUCCESS);
}
