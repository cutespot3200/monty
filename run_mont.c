#include "monty.h"
#include <string.h>

void loose_tokens(void);
unsigned int token_arr_len(void);
int is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int run_mont(FILE *script_fd);

/**
 * loose_tokens - Loosens global op_toks string array.
 */
void loose_tokens(void)
{
	size_t i = 0;

	if (op_toks == NULL)
		return;

	for (i = 0; op_toks[i]; i++)
		free(op_toks[i]);

	free(op_toks);
}

/**
 * token_arr_len - Derives len of current op_toks.
 *
 * Return: Len of current op_toks (as int).
 *
 */
unsigned int token_arr_len(void)
{
	unsigned int toks_len = 0;

	while (op_toks[toks_len])
		toks_len++;
	return (toks_len);
}

/**
 * is_empty_line - Confirms if line read from getline only contains delimiters.
 * @line: Pointer to the line.
 * @delims: String of delimiter characters.
 *
 * Return: If line only contains delimiters - 1.
 *         Else - 0.
 */
int is_empty_line(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}

/**
 * get_op_func - Joins opcode with corresponding function.
 * @opcode: The Opcode to match.
 *
 * Return: Pointer to corresponding function.
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", mont_push},
		{"pall", mont_pall},
		{"pint", mont_pint},
		{"pop", mont_pop},
		{"swap", mont_swap},
		{"add", mont_add},
		{"nop", mont_nop},
		{"sub", mont_sub},
		{"div", mont_div},
		{"mul", mont_mul},
		{"mod", mont_mod},
		{"pchar", mont_pchar},
		{"pstr", mont_pstr},
		{"rotl", mont_rotl},
		{"rotr", mont_rotr},
		{"stack", mont_stack},
		{"queue", mont_queue},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}

	return (NULL);
}

/**
 * run_mont - To execute a Mont bytecodes script.
 * @script_fd: Descriptor for open Mont bytecodes script.
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int run_mont(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (initialize_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, script_fd) != -1)
	{
		line_number++;
		op_toks = strtow(line, DELIMS);
		if (op_toks == NULL)
		{
			if (is_empty_line(line, DELIMS))
				continue;
			loose_stack(&stack);
			return (malloc_err());
		}
		else if (op_toks[0][0] == '#') /* comment line */
		{
			loose_tokens();
			continue;
		}
		op_func = get_op_func(op_toks[0]);
		if (op_func == NULL)
		{
			loose_stack(&stack);
			exit_status = unknown_op_err(op_toks[0], line_number);
			loose_tokens();
			break;
		}
		prev_tok_len = token_arr_len();
		op_func(&stack, line_number);
		if (token_arr_len() != prev_tok_len)
		{
			if (op_toks && op_toks[prev_tok_len])
				exit_status = atoi(op_toks[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			loose_tokens();
			break;
		}
		loose_tokens();
	}
	loose_stack(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (malloc_err());
	}

	free(line);
	return (exit_status);
}
