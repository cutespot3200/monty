#include "monty.h"

int usage_err(void);
int malloc_err(void);
int f_open_err(char *filename);
int unknown_op_err(char *opcode, unsigned int line_number);
int no_int_err(unsigned int line_number);

/**
 * usage_err - Prints usage err msgs.
 *
 * Return: (EXIT_FAILURE) always.
 */
int usage_err(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * malloc_err - Prints malloc err msgs.
 *
 * Return: (EXIT_FAILURE) always.
 */
int malloc_err(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}
/**
 * f_open_err - Prints file opening err msgs without the  file name.
 * @filename: Name of file failed to open
 *
 * Return: (EXIT_FAILURE) always.
 */
int f_open_err(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * unknown_op_err - Prints unknown instruction err msgs.
 * @opcode: Opcode where err occurrs.
 * @line_number: Line number in Monty bytecodes file where err occurs.
 *
 * Return: (EXIT_FAILURE) always.
 */
int unknown_op_err(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
			line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * no_int_err - Prints invalid monty_push argument err msgs.
 * @line_number: Line number in Monty bytecodes file where err occurs.
 *
 * Return: (EXIT_FAILURE) always.
 */
int no_int_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
