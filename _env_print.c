#include "shell.h"

/**
 * _env_print - Replace vars in the cmd.
 * Return: Nothing.
 */
void _env_print(void)
{
	int n = 0;
	int m = 0;

	while (environ[n])
	{
		m = 0;
		while (*(environ[n] + m))
		{
			_putchar(*(environ[n] + m));
			m++;
		}
		if (m != 0)
			_putchar('\n');
		n++;
	}
}

/**
 * exect_setenv - Set or modify envr var.
 * @args: Command-line args.
 * Return: Nothing.
 */
void exect_setenv(char **args)
{
	if (args[1] != NULL && args[2] != NULL)
	{
		if (setenv(args[1], args[2], 1) == -1)
		{
			perror("setenv");
		}
	}
	else
	{
		write(STDERR_FILENO, "\n", 2);
	}
}



/**
 * exect_unsetenv - Unset the env var.
 * @args: Cmd-line args.
 * Return: Nothing.
 */
void exect_unsetenv(char **args)
{
	if (args[1] != NULL)
	{
		if (unsetenv(args[1]) == -1)
		{
			perror("unsetenv");
		}
	}
	else
	{
		write(STDERR_FILENO, "unsetenv: Missing argument\n", 27);
	}
}
