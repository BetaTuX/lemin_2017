/*
** EPITECH PROJECT, 2018
** Lem in
** File description:
** check end game for lem in
*/

#include "lemin.h"

l_list_t *check_end(l_list_t *list_tunnels)
{
	for (l_list_t *cur = list_tunnels; cur; cur = cur->next) {
		if (cur && LIST(cur)->data && ROOM(LIST(cur))->type == END) {
			my_rev_list((l_list_t **)&(cur->data));
			return ((l_list_t *)cur->data);
		}
	}
	return (NULL);
}