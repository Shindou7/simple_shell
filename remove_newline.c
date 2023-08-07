#include "shell.h"

/**Function to remove the trailing newline character from strings*/
/**
 * remove_newline - function to remove the "\n".
 * @strings: signal_Handler.
 * Return: nothing.
 */
char *remove_newline(char *strings)
{
	char *lengt = strings;

	while (*lengt)
	{
		if (*lengt == '\n')
			*lengt = '\0';
		lengt++;
	}
	return (strings);
}
