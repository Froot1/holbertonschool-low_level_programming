/*
 * File: 101-_mul.c
 * Auth: Fahad Alonazi
 */
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * larger_num - get larger num
 * @n1: n1
 * @n2: n2
 * Return: larger index.
 */
int larger_num(char *n1, char *n2)
{
	int l1, l2;

	l1 = strlen(n1);
	l2 = strlen(n2);
	/*missing cases like 001 19*/
	if (l1 > l2)
		return (1);
	else if (l1 < l2)
		return (2);
	else if ((*n1 == '\0') && (*n2 == '\0'))
	{
		return (1);
	}
	else if ((*n1 != '\0') && (*n2 != '\0'))
	{
		if (*n1 >= *n2)
			return (1);
		if (*n1 < *n2)
			return (2);
	}
	return ((larger_num(n1++, n2++)));
}
/**
 * is_number - is it number
 * @n: n1
 * Return: 1 ture or 0 false
 */
int is_number(char *n)
{
	while (*n)
	{
		if (!((*n >= '0') && (*n <= '9')))
			return (0);
		n++;
	}
	return (1);
}
/**
 * mul_number - get larger num
 * @n1: n1
 * @n2: n2
 * Return: larger index.
 */
char *mul_number(char *n1, char *n2)
{
	char **v;

	(void) v;
	(void) n1;
	(void) n2;
	return (NULL);
}
/**
 * main - multiplies two numbers "arguments"
 * @argc: argument count
 * @argv: argument vector
 * Return: (0) success or (1) faild
 */
int main(int argc, char *argv[])
{
	int larger, isNumbers;
	char *total;

	(void) total;
	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	isNumbers = is_number(argv[1]) +  is_number(argv[1]);
	if (isNumbers != 2)
	{
		printf("Error\n");
		exit(98);
	}
	larger = larger_num(argv[1], argv[2]);

	if (larger == 1)
		total = mul_number(argv[1], argv[2]);
	else
		total = mul_number(argv[2], argv[1]);

	printf("%lu\n", (atol(argv[1]) * atol(argv[2])));
	return (0);
}
