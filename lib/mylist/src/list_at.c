/*
** EPITECH PROJECT, 2018
** mylist lib
** File description:
** returns 'l_list_t' node at index 'ind'
*/

#include "mylist.h"

l_list_t *list_at(l_list_t *list, int ind)
{
	l_list_t *cur = list;

	for (int i = 0; i < ind && cur; i++, cur = cur->next);
	if (!cur)
		return (NULL);
	else
		return (cur);
}