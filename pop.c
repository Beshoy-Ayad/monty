#include "monty.h"

/**
 * pop - remove the top element of the stack.
 *
 * @stack: Pointer to the stack.
 * @line_number: Line number of the instruction.
 *
 * Return: void.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	node = *stack;
	*stack = (*stack)->next;
	free(node);
}
