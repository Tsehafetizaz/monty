#ifndef MONTY_H
#define MONTY_H
#define USAGE_ERROR 1
#define OPEN_FILE_ERROR 2
#define MALLOC_ERROR 3
#define UNKNOWN_OPCODE_ERROR 4

#include <stdio.h>
#include <stdlib.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number, char *arg);
} instruction_t;

void push(stack_t **stack, unsigned int line_number, char *arg);
void pall(stack_t **stack, unsigned int line_number, char *arg);
void pint(stack_t **stack, unsigned int line_number, char *arg);
void pop(stack_t **stack, unsigned int line_number, char *arg);
void swap(stack_t **stack, unsigned int line_number, char *arg);
void add(stack_t **stack, unsigned int line_number, char *arg);
void free_stack(stack_t **stack);
int parse_file(const char *file, stack_t **stack);
int is_number(const char *str);



#endif /* MONTY_H */
