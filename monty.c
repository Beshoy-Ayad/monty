#include "monty.h"

/**
 * main - program main.
 * @argc: Number of arguments.
 * @argv: Array of arguments.
 *
 * Return: 0 if successful, 1 otherwise.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL, *space = NULL, *token;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	instruction_t *instruction;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		space = line;
		skip_comment(space);
		while (*space && *space == ' ')
			space++;
		if (strcmp(space, "$\n") == 0)
			continue;

		token = strtok(space, " \t$\n");
		instruction = get_instruction(token);
		line_number++;
		if (instruction == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
			free_and_close(line, file);
			exit(EXIT_FAILURE);
		}
		instruction->f(&stack, line_number);
	}
	free_and_close(line, file);
	return (EXIT_SUCCESS);
}

/**
 * free_and_close - free and closes the file.
 *
 * @line: Pointer to the line.
 * @file: Pointer to the file.
 *
 * Return: void.
 */
void free_and_close(char *line, FILE *file)
{
	free(line);
	fclose(file);
}

/**
 * skip_comment -  skips comments.
 *
 * @line: Pointer to the line.
 *
 * Return: void.
 */
void skip_comment(char *line)
{
	char *comment_start = NULL;

	comment_start = strchr(line, '#');
	if (comment_start != NULL)
		*comment_start = '\0';
}
