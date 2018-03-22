/*
** EPITECH PROJECT, 2017
** CPool_Day11
** File description:
** Reverses a linked list
*/

#include <stdlib.h>
#include "mylist.h"

int my_rev_list(l_list_t **begin)
{
	l_list_t *cpy = NULL;
	l_list_t *tmp = NULL;
	int i = 0;

	for (; *begin != 0; i++) {
		push(&cpy, (*begin)->data);
		tmp = *begin;
		*begin = (*begin)->next;
		free(tmp);
	}
	*begin = cpy;
	return (i);
}