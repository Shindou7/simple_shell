#include "shell.h"

/**
 * exect_cd - modify the current dir of the process.
 * @tok: Command-line args.
 * @ligne: Command-line args.
 * Return: Nothing.
 */
void exect_cd(char **tok, char *ligne)
{
	int exit_status = 0;

	if (tok[1] == NULL || (!_strcmp(tok[1], "0")))
	{
		free_Pointers(tok);
		free(ligne);
		exit(0);
	}
	exit_status = _atoi(tok[1]);
	if (exit_status != 0)
	{
		free_Pointers(tok);
		free(ligne);
		exit(exit_status);
	}
	else
	{
		_puts("exit: Illegal number: ");
		_puts(tok[1]);
		_puts("\n");
		exit(2);
	}
	free_Pointers(tok);
	free(ligne);
	exit(EXIT_SUCCESS);
}




