/*
 * File: 0-strcat.c
 * Auth: Fahad Alonazi
 */

#include "main.h"

/**
 * _strcat - Function that concatenates two strings
 * @dest: First string to be concatenated
 * @src: Second string to be concatenated
 * Return: Pointer to the resulting
 */
char *_strcat(char *dest, char *src)
{
	int i, j, a, b = 0;

	while (1)
	{
		if (*(dest + i) == '\0')
			break;

		i++;
	}

	while (1)
	{
		if (*(src + j) == '\0')
			break;

		j++;
	}

	for (a = i; a < i + j; a++)
	{
		*(dest + a) = *(src + b);
		b++;
	}

	*(dest + a) = '\0';

	return (dest);
}
