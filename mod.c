#include "monty.h"

/**
 * mod_op - function that computes the the top two
 * element of the stack by.
 *
 * @stack: Pointer to the stack.
 * @line_number: Line number of the instruction.
 *
 * Return: void.
 */
void mod_op(stack_t **stack, unsigned int line_number)
{
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

	remainder = (*stack)->next->n % (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = remainder;
}
