#include "monty.h"

/**
 * mul_op - multiplies the top two element of the stack.
 *
 * @stack: Pointer to the stack.
 * @line_number: Line number of the instruction.
 *
 * Return: void.
 */
void mul_op(stack_t **stack, unsigned int line_number)
{
	int product;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	product = (*stack)->next->n * (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = product;
}
