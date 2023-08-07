#include "shell.h"

/**
* _executeCommand - Executes a command
* @command: The command to execute
* @arguments: The options or flag to the command
* Return: A integer status value
*/
int _executeCommand(char *command, char **arguments)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("fork failed");
		return (-1);
	}
	else if (pid == 0)
	{
		execve(command, arguments, environ);
		perror("execve failed");
		exit(2);
	}
	else
	{
		do {
			if (waitpid(pid, &status, WUNTRACED) == -1)
			{
				perror("waitpid failed");
				return (-1);
			}
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (0);
}


/**
* concatenate_path - .........
* @git: ...........
* @pot: ......
* Return: name
*/
char *concatenate_path(char *git, char *pot)
{
	int pot_len = 0, git_len = 0, result = 0;

	pot_len = _strlen(pot);
	git_len = _strlen(git);

	result = sizeof(char) * (git_len + pot_len + 2);
	git = _realloc(git, (git_len + 1), result);
	if (!git)

		return (NULL);

	_strcat(git, "/");
	_strcat(git, pot);

	return (git);
}


/**
* find - .........
* @gite: ...........
* Return: name
*/
char *find(char *gite)
{
	char *_envpath = NULL, **toky = NULL;
	int n = 0, numb_del = 0;
	struct stat sb;

	if (gite)
	{
		if (stat(gite, &sb) != 0 && gite[0] != '/')
		{
			_envpath = _getenv("PATH");
			numb_del = countOccurrences(_envpath, ":") + 1;
			toky = custom_Tokenize(_envpath, ":", numb_del);

			while (toky[n])
			{
				toky[n] = concatenate_path(toky[n], gite);

				if (stat(toky[n], &sb) == 0)
				{
					free(gite);
					gite = _strdup(toky[n]);
					free_comd_args(_envpath);
					free_Pointers(toky);
					return (gite);
				}
				n++;
			}
			free_comd_args(_envpath);
			free_Pointers(toky);
		}
		if (stat(gite, &sb) == 0)
			return (gite);
	}
	free(gite);
	return (NULL);
}
