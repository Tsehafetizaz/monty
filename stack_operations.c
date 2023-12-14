#include "monty.h"
#include <string.h>

/**
 * push - Pushes an element to the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file
 * @arg: Argument for the push operation, expected to be a string
 */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
stack_t *new_node;
int num;


if (arg == NULL)
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}

num = atoi(arg);
if ((num == 0 && strcmp(arg, "0") != 0))
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}

new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

new_node->n = num;
new_node->prev = NULL;
new_node->next = *stack;
if (*stack != NULL)
(*stack)->prev = new_node;
*stack = new_node;
}

/**
 * pall - Prints all values on the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file (unused)
 * @unused: Unused parameter, included to match function signature
 */
void pall(stack_t **stack, unsigned int line_number, char *unused)
{
stack_t *temp = *stack;
(void)line_number;
(void)unused;
while (temp != NULL)
{
printf("%d\n", temp->n);
temp = temp->next;
}
}
