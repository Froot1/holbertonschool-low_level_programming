/*
 * File: 0-_strcat.c
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
	int i, c;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (c = 0; src[c] != '\0'; c++)
	{
		dest[i] = src[c];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}
