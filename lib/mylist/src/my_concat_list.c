/*
** EPITECH PROJECT, 2017
** CPool_Day11
** File description:
** Applies a function, given as argument, to the data of each node
*/

#include "mylist.h"

void my_concat_list(l_list_t **begin1, l_list_t *begin2)
{
	l_list_t *cur = *begin1;

	while (cur->next != 0)
		cur = cur->next;
	cur->next = begin2;
}
