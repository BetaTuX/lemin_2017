/*
** EPITECH PROJECT, 2017
** CPE_lemin_2017
** File description:
** Return a ptr to a room
*/

/* File created the 22/03/2018 at 18:36:40 by julian.frabel@epitech.eu */

#include "my.h"
#include "lemin.h"

room_t *get_room_by_name(game_t *game, const char *name)
{
	l_list_t *current = NULL;
	room_t *room = NULL;

	for (current = game->rooms; current != NULL; current = current->next) {
		room = current->data;
		if (my_strcmp(room->name, name) == 0)
			return (room);
	}
	return (NULL);
}