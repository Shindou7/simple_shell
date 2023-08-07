#include "shell.h"


/**
 * _strcmp - check the code.
 *@s1: first string.
 *@s2: second string.
 * Return: 0.
 */

int _strcmp(char *s1, char *s2)
{
	int a = 0;
	int b = 0;

	while (b == 0)
	{
		if ((*(s1 + a) == '\0') && (*(s2 + a) == '\0'))
			break;
		b = *(s1 + a) - *(s2 + a);
		a++;
	}
	return (b);
}


/**
 * _strcpy - copies the string pointed to by src,
 * @dest: destination add.
 * @src: source add.
 * Return: value the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}


/**
 * _atoi - converts str to integer.
 * @s: put string.
 * Return: integer
 */

int _atoi(char *s)
{
	int sign = 1;
	unsigned int numb = 0;
	int found_numb = 0;

	while (*s)
	{
		if (*s == '-')
			sign *= -1;
		else if (*s >= '0' && *s <= '9')
		{
			numb = numb * 10 + (*s - '0');
			found_numb = 1;
		}
		else if (found_numb)
			break;
		s++;
	}
	return (numb * sign);
}


/**
 * _puts - prints a string.
 * @str: put string.
 * Return: No return.
 */
void _puts(char *str)
{
	int count = 0;

	while (count >= 0)
	{
		if (str[count] == '\0')
		{
			_putchar('\n');
			break;
		}
		_putchar(str[count]);
		count++;
	}
}


/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
