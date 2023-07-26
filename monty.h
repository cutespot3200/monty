#ifndef __MONTY_H__
#define __MONTY_H__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

#define DELIMS " \n\t\a\b"
#define STACK 0
#define QUEUE 1

/* OPCODE FUNCS */
void mont_queue(stack_t **stack, unsigned int line_number);
void mont_push(stack_t **stack, unsigned int line_number);
void mont_stack(stack_t **stack, unsigned int line_number);
void mont_pall(stack_t **stack, unsigned int line_number);
void mont_rotr(stack_t **stack, unsigned int line_number);
void mont_pint(stack_t **stack, unsigned int line_number);
void mont_rotl(stack_t **stack, unsigned int line_number);
void mont_pop(stack_t **stack, unsigned int line_number);
void mont_pstr(stack_t **stack, unsigned int line_number);
void mont_swap(stack_t **stack, unsigned int line_number);
void mont_pchar(stack_t **stack, unsigned int line_number);
void mont_add(stack_t **stack, unsigned int line_number);
void mont_mod(stack_t **stack, unsigned int line_number);
void mont_nop(stack_t **stack, unsigned int line_number);
void mont_div(stack_t **stack, unsigned int line_number);
void mont_sub(stack_t **stack, unsigned int line_number);
void mont_mul(stack_t **stack, unsigned int line_number);

/* GLOBAL OPCODE TOKENS */
extern char **op_toks;

/* PRIMARY INTERPRETER FUNCS */
void set_op_tok_err(int error_code);
void  loose_stack(stack_t **stack);
int run_mont(FILE *script_fd);
int initialize_stack(stack_t **stack);
unsigned int token_arr_len(void);
int check_mode(stack_t *stack);
void loose_tokens(void);

/* ERR MESSAGES & ERR CODES */
int pchar_err(unsigned int line_number, char *message);
int usage_err(void);
int div_err(unsigned int line_number);
int malloc_err(void);
int short_stack_err(unsigned int line_number, char *op);
int f_open_err(char *filename);
int pint_err(unsigned int line_number);
int unknown_op_err(char *opcode, unsigned int line_number);
int pop_err(unsigned int line_number);
int no_int_err(unsigned int line_number);

/* CUSTOM STANDARD LIBRARY FUNCS */
char **strtow(char *str, char *delims);
char *get_int(int n);

#endif /* __MONTY_H__ */
