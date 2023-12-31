#include "monty.h"

/**
 * pchar_op - prints the char at the top of the stack.
 *
 * @stack: Pointer to the stack.
 * @line_number: Line number of the instruction.
 *
 * Return: void.
 */
void pchar_op(stack_t **stack, unsigned int line_number)
{
	int ascii_value;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		 exit(EXIT_FAILURE);
	}

	ascii_value = (*stack)->n;

	if (ascii_value < 0 || ascii_value > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", ascii_value);
}
