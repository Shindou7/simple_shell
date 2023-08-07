#include "shell.h"

/**
 * _strdup - ....
 * @str: the string to duplicate
 * Return: a pointer .....
 */

char *_strdup(char *str)
{
	char *dupl;
	unsigned int i, len;

	if (str == NULL)
	{
		return (NULL);
	}

	for (len = 0; str[len] != '\0'; len++)
	{
		;
	}
	dupl = malloc(sizeof(char) * (len + 1));
	if (dupl == NULL)
	{
		return (NULL);
	}
	for (i = 0; i <= len; i++)
	{
		dupl[i] = str[i];
	}
	return (dupl);
}

/**
 * process_input_semicolon - ....
 * @input: the string to duplicate
 * Return: a pointer .....
 */
void process_input_semicolon(char *input)
{
	char **commands = custom_Tokenize(input, ";", 100);
	int i;
	char *command, *end;

	if (!commands)
		return;

	for (i = 0; commands[i]; i++)
	{
		command = commands[i];
		while (*command == ' ' || *command == '\t')
			command++;
		end = command + strlen(command) - 1;
		while (end > command && (*end == ' ' || *end == '\t' || *end == '\n'))
			*end-- = '\0';
		if (*command)
			process_input(command);
	}
	free_Pointers(commands);
}
