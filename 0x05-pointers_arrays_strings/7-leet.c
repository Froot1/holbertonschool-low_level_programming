/*
 * File: 7-_leet.c
 * Auth: Fahad Alonazi
 */

#include "main.h"

/**
 * leet - Encodes a string into 1337 speak
 * @str: The input string to be encoded
 *
 * Return: The encoded string
 */

char *leet(char *str)
{
	char leetChars[] = "aAeEoOtTlL";
	char leetSubs[] = "4433007711";
	char *ptr = str;
	int i;

	while (*ptr)
	{
		for (i = 0; i < 10; i++)
		{
			if (*ptr == leetChars[i])
			{
				*ptr = leetSubs[i];
				break;
			}
		}
		ptr++;
	}
	return (str);
}

