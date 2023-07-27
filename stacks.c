#include "monty.h"
#include <string.h>

void loose_stack(stack_t **stack);
int initialize_stack(stack_t **stack);
int check_mode(stack_t *stack);

/**
 * loose_stack - This will free a stack_t stack.
 * @stack: Pointer to top (stack) or
 *         bottom (queue) of stack_t.
 */
void loose_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * initialize_stack - This initializes stack_t stack with beginning
 *              stack and ending queue nodes.
 * @stack: Pointer to unitialized stack_t stack.
 *
 * Return: Incase of error - EXIT_FAILURE.
 *         Else - EXIT_SUCCESS.
 */
int initialize_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (malloc_err());

	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}

/**
 * check_mode - This checks if a stack_t linked list is in stack or queue mode.
 * @stack: Pointer to top (stack) or bottom (queue)
 *         of stack_t linked list.
 *
 * Return: If stack_t is in stack mode - STACK (0).
 *         If stack_t is in queue mode - QUEUE (1).
 *         Else - 2.
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
