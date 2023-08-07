#include "shell.h"
#include <string.h>

/**
 * EX_builtin_comd - the main code.
 * @tok: The number of command-line args.
 * @ligne: An array of command-line args.
 * Return: 0.
 */
/**Function to handle the built-in cmds*/
int EX_builtin_comd(char **tok, char *ligne)
{
	int i = 0;

	char *LisCmds[] = {"exit", "cd", "help", "env", "setenv", "unsetenv", NULL};

	for (i = 0; LisCmds[i]; i++)
	{
		if (strcmp(tok[0], LisCmds[i]) == 0)
		{
			switch (i)
			{
				case 0:
					exect_cd(tok, ligne);
					break;
				case 1:
					_cd(tok);
					return (1);
				case 2:
					display_shell_help();
					return (1);
				case 3:
					_env_print();
					return (1);
				case 4:
					exect_setenv(tok);
					return (1);
				case 5:
					exect_unsetenv(tok);
					return (1);
				default:
					break;
			}
		}
	}
	return (0);
}

/**
* _cd - the main code.
* @tok: The number of command-line args.
* Return: 0.
*/
void _cd(char **tok)
{
	char *house, *p_dir;
	char cwd[PATH_MAX];

	if (tok[1] == NULL)
	{
		house = getenv("HOME");
		if (house)
		{
			if (chdir(house) != 0)
				perror("cd");
		}
		else
			_puts("cd: No $HOME variable found.\n");
	}
	else if (strcmp(tok[1], "-") == 0)
	{
		p_dir = getenv("OLDPWD");
		if (p_dir)
		{
			if (chdir(p_dir) != 0)
				perror("cd");
			_puts(p_dir);
			_puts("\n");
		} else
			_puts("cd: No p directory found.\n");
	} else
	{
		if (chdir(tok[1]) != 0)
			perror("cd");
	}
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		setenv("PWD", cwd, 1);
		setenv("OLDPWD", cwd, 1);
	}
	else
		perror("getcwd");
}
