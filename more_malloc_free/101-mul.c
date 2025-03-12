/*
 * File: 101-_mul.c
 * Auth: Fahad Alonazi
 */

#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * is_positive_number - Checks if a string represents a positive number
 * @str: The string to check
 *
 * Return: 1 if the string is a positive number, 0 otherwise
 */
int is_positive_number(char *str)
{
	if (!str || *str == '\0')
		return (0);

	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}

	return (1);
}

/**
 * multiply_strings - Multiplies two large positive numbers as strings
 * @num1: First number as string
 * @num2: Second number as string
 *
 * Return: The result as a dynamically allocated string
 */
char *multiply_strings(char *num1, char *num2)
{
	int len1 = strlen(num1), len2 = strlen(num2);
	int *result = calloc(len1 + len2, sizeof(int));
	char *final_result;
	int i, j, product;

	if (!result)
	{
		printf("Error\n");
		exit(98);
	}

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			product = (num1[i] - '0') * (num2[j] - '0') + result[i + j + 1];
			result[i + j + 1] = product % 10;
			result[i + j] += product / 10;
		}
	}

	final_result = malloc(len1 + len2 + 1);
	if (!final_result)
	{
		printf("Error\n");
		exit(98);
	}

	i = 0;
	while (i < len1 + len2 && result[i] == 0)
		i++;

	j = 0;
	while (i < len1 + len2)
		final_result[j++] = result[i++] + '0';

	final_result[j] = '\0';
	free(result);

	return (*final_result ? final_result : strdup("0"));
}

/**
 * main - Multiplies two positive numbers passed as arguments
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	char *result;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	if (!is_positive_number(argv[1]) || !is_positive_number(argv[2]))
	{
		printf("Error\n");
		return (98);
	}

	result = multiply_strings(argv[1], argv[2]);
	printf("%s\n", result);
	free(result);

	return (0);
}
