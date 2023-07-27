#include "monty.h"

int short_stack_err(unsigned int line_number, char *op);
int div_err(unsigned int line_number);
int pop_err(unsigned int line_number);
int div_err(unsigned int line_number);
int pchar_err(unsigned int line_number, char *message);

/**
 * pop_err - Prints pop err msgs for empty stacks.
 * @line_number: Lines num in script where err occurs.
 *
 * Return: (EXIT_FAILURE) always.
 */
int pop_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pint_err - Prints pint err msgs for empty stacks.
 * @line_number: Lines num in Monty bytecodes file where err occurrs.
 *
 * Return: (EXIT_FAILURE) always.
 */
int pint_err(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * short_stack_err - Prints monty math function err messages
 *                     for stacks/queues smaller than two nodes.
 * @line_number: Lines num in Monty bytecodes file where err occurrs.
 * @op: Operation where the err occurrs.
 *
 * Return: (EXIT_FAILURE) always.
 */
int short_stack_err(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * div_err - Prints division err msgs for division by 0.
 * @line_number: Lines num in Monty bytecodes file where err occurrs.
 *
 * Return: (EXIT_FAILURE) always.
 */
int div_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pchar_err - Prints pchar err msgs for empty stacks
 *               empty stacks and non-character values.
 * @line_number: Line num in Monty bytecodes file where err occurrs.
 * @message: The corresponding err message to print.
 *
 * Return: (EXIT_FAILURE) always.
 */
int pchar_err(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}
