#include "monty.h"

/**
 * get_instruction - function that call right function
 * corresponding to an opcode.
 *
 * @opcode: string command.
 *
 * Return: A pointer to the instruction_t struct or NULL.
 */
instruction_t *get_instruction(char *opcode)
{
	int i;

	static instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_op},
		{"mul", mul_op},
		{"mod", mod_op},
		{"pchar", pchar_op},
		{NULL, NULL}};
	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
			return (&instructions[i]);
	}
	return (NULL);
}
