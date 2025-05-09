/*
 * File: 8-print_array.c
 * Auth: Fahad Alonazi
 */

#include "main.h"
#include <stdio.h>

/**
 * print_array - function that prints n elements of an array of integers
 * followed by a new line
 *
 * @a: parameter defined in main
 * @n: parameter defined in main
 *
 * Return: void
 */

void print_array(int *a, int n)
{
	int j;

	for (j = 0; j < n; j++)
		if (j < n - 1)
		{
			printf("%d, ", a[j]);
		}
		else
		{
			printf("%d", a[j]);
		}
	printf("\n");
}
