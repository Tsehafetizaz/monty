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


if (arg == NULL || !is_number(arg))
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

/**
 * pint - Prints all values on the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file (unused)
 * @unused: Unused parameter, included to match function signature
 */

void pint(stack_t **stack, unsigned int line_number, char *unused)
{
if (*stack == NULL)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}

printf("%d\n", (*stack)->n);
(void)unused;
}

/**
 * pop - removes values on the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file (unused)
 * @unused: Unused parameter, included to match function signature
 */

void pop(stack_t **stack, unsigned int line_number, char *unused)
{
stack_t *temp;
if (*stack == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}

temp = *stack;
*stack = (*stack)->next;
free(temp);

if (*stack != NULL)
{
(*stack)->prev = NULL;
}

(void)unused;
}

/**
 * swap - swaps values on the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file (unused)
 * @unused: Unused parameter, included to match function signature
 */

void swap(stack_t **stack, unsigned int line_number, char *unused)
{
stack_t *temp;
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

temp = *stack;
*stack = (*stack)->next;
temp->next = (*stack)->next;
(*stack)->prev = NULL;
if (temp->next != NULL)
{
temp->next->prev = temp;
}
(*stack)->next = temp;
temp->prev = *stack;

(void)unused;
}

