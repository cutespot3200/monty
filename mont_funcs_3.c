#include "monty.h"

void mont_nop(stack_t **stack, unsigned int line_number);
void mont_pchar(stack_t **stack, unsigned int line_number);
void mont_pstr(stack_t **stack, unsigned int line_number);

/**
 * mont_nop - Does nothing for Mont opcode 'nop'.
 * @stack: Pointer to the top mode node of a stack_t linked list.
 * @line_number: Current working line num of Mont bytecodes file.
 */
void mont_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * mont_pchar - Prints character in top val
 *               node of a stack_t linked list.
 * @stack: Pointer to the top mode node of a stack_t linked list.
 * @line_number: Current working line num of Mont bytecodes file.
 */
void mont_pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_err(pchar_err(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_op_tok_err(pchar_err(line_number,
					"value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}

/**
 * mont_pstr - Prints string in a stack_t linked list.
 * @stack: Pointer to top mode node of stack_t linked list.
 * @line_number: Current working line number of a Mont bytecodes file.
 */
void mont_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");

	(void)line_number;
}
