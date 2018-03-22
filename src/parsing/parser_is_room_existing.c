/*
** EPITECH PROJECT, 2017
** CPE_lemin_2017
** File description:
** Return is a room with the same already exist
*/

/* File created the 22/03/2018 at 18:08:27 by julian.frabel@epitech.eu */

#include <stdbool.h>
#include <stdlib.h>
#include "my.h"
#include "match.h"
#include "lemin.h"
#include "parsing.h"

int does_name_already_exist(game_t *game, char *name)
{
	l_list_t *curr = game->rooms;
	room_t *room = NULL;

	for (; curr != NULL; curr = curr->next) {
		room = (room_t *)curr->data;
		if (my_strcmp(name, room->name) == 0)
			return (1);
	}
	return (0);
}