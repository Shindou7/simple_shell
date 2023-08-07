#include "shell.h"
#include <stdio.h>

/**
 * _strlen - check the code.
 * @s: input string.
 *
 * Return: i value.
 */

int _strlen(const char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}




/**
 * _strncpy - copies a string
 * @dest: destination string.
 * @src: source string.
 * @n: the  byte from the source.
 * Return: return to dest value.
 */

char *_strncpy(char *dest, char *src, int n)
{
	int a;

	for (a = 0; a < n && src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}

	for ( ; a < n; a++)
	{
		dest[a] = '\0';
	}

	return (dest);
}


/**
 * _strncat - concatenates two strings,
 * @dest: destination.
 * @src: source.
 * @n: the amount of bytes used from src.
 * Return: pointer to dest.
 */

char *_strncat(char *dest, char *src, int n)
{
	int dest_len = 0;
	int src_len = 0;

	while (*(dest + dest_len) != '\0')
	{
		dest_len++;
	}

	while (src_len < n)
	{
		*(dest + dest_len) = *(src + src_len);
		if (*(src + src_len) == '\0')
			break;
		dest_len++;
		src_len++;
	}
	return (dest);
}

/**
 * _strcat - concatenates two strings,
 * @dest: destination.
 * @src: source.
 * Return: Pointer to dest.
 */

char *_strcat(char *dest, const char *src)
{
	int dest_len = 0;
	int src_len = 0;

	while (*(dest + dest_len) != '\0')
	{
		dest_len++;
	}

	while (src_len >= 0)
	{
		*(dest + dest_len) = *(src + src_len);
		if (*(src + src_len) == '\0')
			break;
		dest_len++;
		src_len++;
	}
	return (dest);
}
