#include "monty.h"

void mont_rotl(stack_t **stack, unsigned int line_number);
void mont_rotr(stack_t **stack, unsigned int line_number);
void mont_stack(stack_t **stack, unsigned int line_number);
void mont_queue(stack_t **stack, unsigned int line_number);

/**
 * mont_rotl - Moves top val of a stack_t linked list to the bottom.
 * @stack: Pointer to top mode node of stack_t linked list.
 * @line_number: Current working line number of Mont bytecodes file.
 */
void mont_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void)line_number;
}

/**
 * mont_rotr - Moves bottom val of a stack_t linked list to the top.
 * @stack: Pointer to top mode node of a stack_t linked list.
 * @line_number: Current working line num of Mont bytecodes file.
 */
void mont_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)line_number;
}

/**
 * mont_stack - Changes a queue to a stack.
 * @stack: Pointer to top mode node of a stack_t linked list.
 * @line_number: Current working line num of Mont bytecodes file.
 */
void mont_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * mont_queue - Changes a stack to a queue.
 * @stack: Pointer to the top mode node of stack_t linked list.
 * @line_number: Current working line num of a Mont bytecodes file.
 */
void mont_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}
