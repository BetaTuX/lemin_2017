/*
** EPITECH PROJECT, 2017
** CPool_Day11
** File description:
** Reverses a linked list
*/

#include "mylist.h"

int my_rev_list(l_list_t **begin)
{
	l_list_t *cpy = NULL;
	int i = 0;

	for (; cpy != 0; i++) {
		push(&cpy, (*begin)->data);
		*begin = (*begin)->next;
	}
	*begin = cpy;
	return (i);
}