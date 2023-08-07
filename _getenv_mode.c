#include "shell.h"

/**
 * _getenv - ......getenv
 * @arg: T......
 * Return: Nothing
 */
char *_getenv(const char *arg)
{
	int index = 0;
	char *_var = NULL;

	for (index = 0; environ[index]; index++)
	{
		if (strncmp(arg, environ[index], _strlen(arg)) == 0)
		{
			_var = strdup(environ[index]);
			while (*_var != '=')
				_var++;
			++_var;
			return (_var);
		}
	}
	return (NULL);
}
