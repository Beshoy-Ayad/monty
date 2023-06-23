#include "monty.h"

/**
 * pall - function that print all the elements in the stack.
 *
 * @stack: Pointer to the stack.
 * @line_number: Line number of the instruction.
 *
 * Return: void.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	(void)line_number;

	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
