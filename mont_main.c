#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **op_toks = NULL;

/**
 * main - the entry point for Mont Int
 *
 * @argc: Count of args passed to program
 * @argv: Pointer to an array of char pointers to args
 *
 * Return: (EXIT_SUCCESS) on success (EXIT_FAILURE) on err
 */
int main(int argc, char **argv)
{
	FILE *script_fd = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (usage_err());
	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
		return (f_open_err(argv[1]));
	exit_code = run_mont(script_fd);
	fclose(script_fd);
	return (exit_code);
}
