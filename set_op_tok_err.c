#include "monty.h"

/**
 * set_op_tok_err - Makes last element of op_toks to be an error code.
 * @err_code: Int to store as a string in op_toks.
 */
void set_op_tok_err(int err_code)
{
	int toks_len = 0, a = 0;
	char *exit_str = NULL;
	char **new_toks = NULL;

	toks_len = token_arr_len();
	new_toks = malloc(sizeof(char *) * (toks_len + 2));
	if (!op_toks)
	{
		malloc_err();
		return;
	}
	while (a < toks_len)
	{
		new_toks[a] = op_toks[a];
		a++;
	}
	exit_str = get_int(err_code);
	if (!exit_str)
	{
		free(new_toks);
		malloc_err();
		return;
	}
	new_toks[a++] = exit_str;
	new_toks[a] = NULL;
	free(op_toks);
	op_toks = new_toks;
}
