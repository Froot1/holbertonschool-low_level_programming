/*
 * File: 0-print_list.c
 * Auth: Fahad Alonazi
 */

#include <stdio.h>
#include "lists.h"

/**
 * print_list - Prints all elements of a list_t list.
 * @h: Pointer to the head of the linked list.
 * Return: The number of nodes.
 */
size_t print_list(const list_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%d] %s\n", h->len, h->str);
		h = h->next;
		count++;
	}

	return (count);
}
