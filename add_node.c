#include "monty.h"

/**
 * add_node - function that add a new node at the
 * beginning of a doubly linked list.
 *
 * @stack: Pointer to a pointer to the stack.
 * @n: value to add to the stack.
 *
 * Return: The address of the new node or NULL.
 */
stack_t *add_node(stack_t **stack, int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		return (NULL);

	node->n = n;
	node->prev = NULL;
	node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = node;

	*stack = node;

	return (node);
}
