#include "shell.h"
#include <stdbool.h>

/**
 * countWords - Replace vars in cmd.
 * @str: ......
 * Return: Nothing.
 */
int countWords(char *str)
{
	int wordCount = 0, inWord = 0;

	while (*str)
	{
		if (*str == ' ' || *str == '\n' || *str == '\t')
		{
			inWord = 0;
		}
		else if (inWord == 0)
		{
			inWord = 1;
			wordCount++;
		}
		str++;
	}
	return (wordCount);
}

/**
 * countOccurrences - Replace vars in cmd.
 * @str: ......
 * @del: .....
 * Return: Nothing.
 */

int countOccurrences(char *str, char *del)
{
	int occurrenceCount = 0;
	int ptr = 0;
	int m = 0;

	while (del[occurrenceCount])
	{
		ptr = 0;
		while (str[ptr])
		{
			if (str[ptr] == del[occurrenceCount])
			{
				m++;
			}
			ptr++;
		}
		occurrenceCount++;
	}
	return (m);
}
