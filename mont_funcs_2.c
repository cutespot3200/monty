#include "monty.h"

void mont_add(stack_t **stack, unsigned int line_number);
void mont_sub(stack_t **stack, unsigned int line_number);
void mont_div(stack_t **stack, unsigned int line_number);
void mont_mul(stack_t **stack, unsigned int line_number);
void mont_mod(stack_t **stack, unsigned int line_number);

/**
 * mont_add - Adds top two val of stack_t linked list.
 * @stack: Pointer to top mode node of stack_t linked list.
 * @line_number: Current working line num of Mont bytecodes file.
 *
 * Description: Result is stored in second val node
 *              from the top and top val is removed.
 */
void mont_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_err(short_stack_err(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	mont_pop(stack, line_number);
}

/**
 * mont_sub - Removes second val from top of
 *             a stack_t linked list by top val.
 * @stack: Pointer to top mode node of stack_t linked list.
 * @line_number: Current working line num of Mont bytecodes file.
 *
 * Description: Result is stored in second val node
 *              from the top and top val is removed.
 */
void mont_sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_err(short_stack_err(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	mont_pop(stack, line_number);
}

/**
 * mont_div - Divides second val from top of
 *             a stack_t linked list by top val.
 * @stack: Pointer to top mode node of stack_t linked list.
 * @line_number: Current working line num of Mont bytecodes file.
 *
 * Description: Result is stored in second val node
 *              from the top and top val is removed.
 */
void mont_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_err(short_stack_err(line_number, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_err(div_err(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	mont_pop(stack, line_number);
}

/**
 * mont_mul - Multiplies second val from top of
 *             a stack_t linked list by top val.
 * @stack: Pointer to top mode node of a stack_t linked list.
 * @line_number: Current working line num of Mont bytecodes file.
 *
 * Description: Result is stored in second val node
 *              from the top and top val is removed.
 */
void mont_mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_err(short_stack_err(line_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	mont_pop(stack, line_number);
}

/**
 * mont_mod - Computes modulus of second val from the
 *             top of stack_t linked list by top value.
 * @stack: Pointer to the top mode node of a stack_t linked list.
 * @line_number: Current working line num of a Mont bytecodes file.
 *
 * Description: Result is stored in the second val node
 *              from the top and top val is removed.
 */
void mont_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_err(short_stack_err(line_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_err(div_err(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	mont_pop(stack, line_number);
}
