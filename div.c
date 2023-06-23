#include "monty.h"

/**
 * div_op - function that divides the top two element of the stack.
 *
 * @stack: Pointer to the stack.
 * @line_number: Line number of the instruction.
 *
 * Return: void.
 */
void div_op(stack_t **stack, unsigned int line_number)
{
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

	quotient = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = quotient;
}
