/*
 * File: 100-set_string.c
 * Auth: Fahad Alonazi
 */

#include "main.h"

/**
 * set_string - Sets the value of a pointer to a char.
 * @s: The pointer.
 * @to: The char.
 */
void set_string(char **s, char *to)
{
	*s = to;
}
