/*
 * File: 6-puts2.c
 * Auth: Fahad Alonazi
 */

#include "main.h"

/**
 * puts2 - Prints one char out of two of a string.
 * @str: The string containing characters.
 */
void puts2(char *str)
{
int i = 0;
int j = 0;
int l;

while (str[i] != '\0')
{
i++;
}
l = i - 1;

while (j <= l)
{
if (j % 2 == 0)
{
_putchar(str[j]);
}
j++;
}
_putchar('\n');
}
