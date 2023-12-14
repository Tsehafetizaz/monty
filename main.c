#include "monty.h"

/**
 * main - Entry point for the Monty interpreter
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
stack_t *stack = NULL;

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

if (parse_file(argv[1], &stack) != EXIT_SUCCESS)
{
/* Error handling is done within parse_file */
exit(EXIT_FAILURE);
}

/* Clean up the stack */
free_stack(&stack);

return (EXIT_SUCCESS);
}
