#include "monty.h"

void mont_push(stack_t **stack, unsigned int line_number);
void mont_pall(stack_t **stack, unsigned int line_number);
void mont_pint(stack_t **stack, unsigned int line_number);
void mont_pop(stack_t **stack, unsigned int line_number);
void mont_swap(stack_t **stack, unsigned int line_number);

/**
 * mont_push - Push val to stack_t linked list.
 * @stack: Pointer to top mode node of stack_t linked list.
 * @line_number: Current working line num of Mont bytecodes file.
 */
void mont_push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new;
	int a;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		set_op_tok_err(malloc_err());
		return;
	}

	if (op_toks[1] == NULL)
	{
		set_op_tok_err(no_int_err(line_number));
		return;
	}

	for (a = 0; op_toks[1][a]; a++)
	{
		if (op_toks[1][a] == '-' && a == 0)
			continue;
		if (op_toks[1][a] < '0' || op_toks[1][a] > '9')
		{
			set_op_tok_err(no_int_err(line_number));
			return;
		}
	}
	new->n = atoi(op_toks[1]);

	if (check_mode(*stack) == STACK) /* STACK mode insert at front */
	{
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else /* QUEUE mode insert at end */
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
}

/**
 * mont_pall - Print val of stack_t linked list.
 * @stack: Pointer to top mode node of stack_t linked list.
 * @line_number: Current working line num of Mont bytecodes file.
 */
void mont_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}

/**
 * mont_pint - Print top val of stack_t linked list.
 * @stack: Pointer to top mode node of stack_t linked list.
 * @line_number: Current working line num of Mont bytecodes file.
 */
void mont_pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_err(pint_err(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}


/**
 * mont_pop - Remove top val element of stack_t linked list.
 * @stack: Pointer to top mode node of stack_t linked list.
 * @line_number: Current working line num of Mont bytecodes file.
 */
void mont_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		set_op_tok_err(pop_err(line_number));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}


/**
 * mont_swap - Swap two top val elements of a stack_t linked list.
 * @stack: Pointer to top mode node of a stack_t linked list.
 * @line_number: Current working line num of a Mont bytecodes file.
 */
void mont_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_err(short_stack_err(line_number, "swap"));
		return;
	}
	tmp = (*stack)->next->next;
		(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}
