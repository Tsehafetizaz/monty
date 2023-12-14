#include "monty.h"
#include <string.h>

/**
 * mul - multiplies values on the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file (unused)
 * @unused: Unused parameter, included to match function signature
 */

void mul(stack_t **stack, unsigned int line_number, char *unused)
{
stack_t *temp;
int product;

if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

temp = *stack;
product = (*stack)->n * (*stack)->next->n;
*stack = (*stack)->next;
(*stack)->n = product;
(*stack)->prev = NULL;
free(temp);

(void)unused;
}

/**
 * mod - modifies values on the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file (unused)
 * @unused: Unused parameter, included to match function signature
 */
void mod(stack_t **stack, unsigned int line_number, char *unused)
{
stack_t *temp;
int remainder;

if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

if ((*stack)->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line_number);
exit(EXIT_FAILURE);
}

temp = *stack;
remainder = (*stack)->next->n % (*stack)->n;
*stack = (*stack)->next;
(*stack)->n = remainder;
(*stack)->prev = NULL;
free(temp);

(void)unused;
}
