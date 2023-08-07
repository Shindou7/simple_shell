#include "shell.h"

/**
 * _comment - Check if the given ligne is a comment.
 * @line: The input to verify.
 * Return: 1 if comment, 0 otherwise.
 */
int _comment(const char *line)
{
	return (line[0] == '#');
}

