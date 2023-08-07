#include "shell.h"

/**
 * free_comd_args - Free the allocated memo.
 * @args: The array of command args.
 * Return: Nothing.
 */
void free_comd_args(char *args)
{
	int i = 4;

	while (i >= 0)
	{
		args--;
		i--;
	}
	free(args);
}


/**
 * free_Pointers - Free the allocated memo.
 * @strArray: The array of command args.
 * Return: Nothing.
 */

void free_Pointers(char **strArray)
{
	int i;

	if (strArray)
	{
		for (i = 0; strArray[i] != NULL; i++)
		{
			free(strArray[i]);
		}
		free(strArray);
	}
}


/**
 * _realloc - reallocates a memory block.
 * @ptr: is a pointer to the memory.
 * @old_size:  is the size.
 * @new_size:  is the new size.
 * Return: ptr
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *pointr;
	size_t n;
	char *char_ptr, *char_pointr;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		return (ptr);
	}
	if (new_size == old_size)
		return (ptr);
	pointr = malloc(new_size);

	if (pointr == NULL)
		return (NULL);
	char_ptr = (char *)ptr;
	char_pointr = (char *)pointr;

	for (n = 0; n < old_size && n < new_size; n++)
	{
		char_pointr[n] = char_ptr[n];
	}
	free(ptr);
	return (ptr);
}
