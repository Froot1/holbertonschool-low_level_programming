/*
 * File: 9-_strcpy.c
 * Auth: Fahad Alonazi
 */

#include "main.h"
#include <stdio.h>
/**
 * *_strcpy - This function copies the string pointed to by src
 * including the terminating null byte (\0) to the bueffer pointed
 * to by dest
 * @src: The string to copy
 * @dest: The buffer to copy to
 * Return: The string str
 */
char *_strcpy(char *dest, char *src)
{
	int i, c = 0;

	while (1)
	{
		if (src[c] == '\0')
			break;

		c++;
	}

	for (i = 0; i < c; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	return (dest);
}
