#include "monty.h"

/**
 * sub -subtracts the top tow element of the stack.
 *
 * @stack: Pointer to the stack.
 * @line_number: Line number of the instruction.
 *
 * Return: void.
 */
void sub(stack_t **stack, unsigned int line_number)
{

	int diff;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	diff = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = diff;
}
