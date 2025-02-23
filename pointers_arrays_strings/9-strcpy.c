/*
 * File: 9-strcpy.c
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
	int count = 0;

	while (count >= 0)
	{
		*(dest + count) = *(src + count);
		if (*(src + count) == '\0')
			break;
		count++;
	}
	return (dest);
}
