#include "monty.h"

/**
 * print_error - Prints error messages based on error code
 * @error_code: Error code
 * @line_number: Line number for the error in the file
 */
void print_error(int error_code, unsigned int line_number)
{
switch (error_code)
{
case USAGE_ERROR:
fprintf(stderr, "USAGE: monty file\n");
break;
case OPEN_FILE_ERROR:
fprintf(stderr, "Error: Can't open file\n");
break;
case MALLOC_ERROR:
fprintf(stderr, "Error: malloc failed\n");
break;
case UNKNOWN_OPCODE_ERROR:
fprintf(stderr, "L%d: unknown instruction\n", line_number);
break;

default:
fprintf(stderr, "Error: Unknown error occurred\n");
}
}
