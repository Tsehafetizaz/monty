#include "monty.h"
#include <string.h>

/**
 * add - adds values on the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file (unused)
 * @unused: Unused parameter, included to match function signature
 */

void add(stack_t **stack, unsigned int line_number, char *unused)
{
stack_t *temp;
int sum;

if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

temp = *stack;
sum = (*stack)->n + (*stack)->next->n;
*stack = (*stack)->next;
(*stack)->n = sum;
(*stack)->prev = NULL;
free(temp);

(void)unused;
}

/**
 * nop - does noting to the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file (unused)
 * @unused: Unused parameter, included to match function signature
 */

void nop(stack_t **stack, unsigned int line_number, char *unused)
{
(void)stack;
(void)line_number;
(void)unused;
}

/**
 * sub - subtracts values on the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file (unused)
 * @unused: Unused parameter, included to match function signature
 */
void sub(stack_t **stack, unsigned int line_number, char *unused)
{
stack_t *temp;
int difference;

if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

temp = *stack;
difference = (*stack)->next->n - (*stack)->n;
*stack = (*stack)->next;
(*stack)->n = difference;
(*stack)->prev = NULL;
free(temp);

(void)unused;
}

/**
 * div_op - divides values on the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file (unused)
 * @unused: Unused parameter, included to match function signature
 */
void div_op(stack_t **stack, unsigned int line_number, char *unused)
{
stack_t *temp;
int quotient;

if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

if ((*stack)->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line_number);
exit(EXIT_FAILURE);
}

temp = *stack;
quotient = (*stack)->next->n / (*stack)->n;
*stack = (*stack)->next;
(*stack)->n = quotient;
(*stack)->prev = NULL;
free(temp);

(void)unused;
}



