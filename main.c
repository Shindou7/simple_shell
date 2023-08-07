#include "shell.h"
#include <signal.h>

/**
* _SignalHandler - Handles the signals
* @signal: The identifier of the signal to handle
* Return: Nothing to returns
*/

void _SignalHandler(int signal)
{
	if (signal == SIGINT)
		write(STDOUT_FILENO, "\n($) ", 5);
}


/**
* custom_Tokenize - ......
* @str: The string to tokenize
* @delimiters:  delimiters toky
* @maxTokens: Tokens maxTokens
* Return: string
*/
char **custom_Tokenize(char *str, char *delimiters, int maxTokens)
{
	char **tokys = NULL;
	char *toky = NULL;
	char *strpys = NULL;
	int tokenCount = 0;
	char *comment_ptr;

	tokys = malloc(sizeof(char *) * (maxTokens + 1));
	if (!tokys)
	{
		return (NULL);
	}
	str = remove_newline(str);
	strpys = _strdup(str);
	toky = strtok(strpys, delimiters);

	while (toky)
	{
		comment_ptr = strchr(toky, '#');
		if (comment_ptr != NULL)
		{
			*comment_ptr = '\0';
		}
		tokys[tokenCount] = _strdup(toky);
		toky = strtok(NULL, delimiters);
		tokenCount++;
	}
	tokys[tokenCount] = NULL;
	free(strpys);
	return (tokys);
}




/**
* Execute_command - Execute_command.
* @command_tokens: The......
* Return: 0.
*/
void Execute_command(char **command_tokens)
{
	command_tokens[0] = find(command_tokens[0]);
	if (command_tokens[0] && access(command_tokens[0], X_OK) == 0)
		_executeCommand(command_tokens[0], command_tokens);
	else
		perror("./hsh");
}

/**
* process_input - Execute_command.
* @ligne: The......
* Return: 0.
*/

void process_input(char *ligne)
{
	char **tokys = NULL;
	int w_len = countWords(ligne);
	int EexecFlag;
	int exit_status;

	if (ligne[0] != '\n' && w_len > 0)
	{
		tokys = custom_Tokenize(ligne, " \t", w_len);
		EexecFlag = EX_builtin_comd(tokys, ligne);
		if (_strcmp(tokys[0], "exit") == 0 && tokys[1] != NULL)
		{
			exit_status = _atoi(tokys[1]);
			free_Pointers(tokys);
			exit(exit_status);
		}
		else
		{
			if (!EexecFlag)
			{
				Execute_command(tokys);
			}
			free_Pointers(tokys);
		}
	}
}

/**
* main - main function for file and interactive mode.
* @argc: The string to tokenize
* @argv:  delimiters toky
* Return: 0.
*/
int main(int argc, char *argv[])
{
	char *ligne = NULL;
	size_t ligne_size = 0;
	ssize_t ligne_len = 0;
	FILE *filename = NULL;

	if (argc == 2)
	{
		filename = fopen(argv[1], "r");
		if (!filename)
		{
			perror("Error opening filename");
			return (EXIT_FAILURE);
		} while ((ligne_len = getline(&ligne, &ligne_size, filename)) >= 0)
		{
			if (ligne_len > 0 && ligne[ligne_len - 1] == '\n')
			{
				ligne[ligne_len - 1] = '\0';
				ligne_len--;
			} process_input(ligne);
		}
		fclose(filename);
	} else
	{
		while (ligne_len >= 0)
		{
			signal(SIGINT, _SignalHandler);
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "($) ", 4);
			ligne_len = getline(&ligne, &ligne_size, stdin);
			if (ligne_len == -1)
			{
				if (isatty(STDIN_FILENO))
					write(STDOUT_FILENO, "\n", 1);
				break;
			}
			process_input_semicolon(ligne);
		} free(ligne);
	} return (0);
}
