/*
** EPITECH PROJECT, 2017
** CPE_lemin_2017
** File description:
** parse a room
*/

/* File created the 22/03/2018 at 18:32:59 by julian.frabel@epitech.eu */

#include <stdbool.h>
#include <stdlib.h>
#include "my.h"
#include "match.h"
#include "lemin.h"
#include "parsing.h"

static room_t *get_default_room(game_t *game, e_room_t room_type, char **args)
{
	room_t *room = NULL;

	if (does_name_already_exist(game, args[0])) {
		my_puterror("lem_in: error: room name already exist: ");
		return (NULL);
	}
	room = malloc(sizeof(*room));
	if (room == NULL) {
		my_puterror("lem_in: system error: malloc failed: ");
		return (NULL);
	}
	room->marked = 0;
	room->name = my_strdup(args[0]);
	room->pos = (vector2i_t){my_getnbr(args[1]), my_getnbr(args[2])};
	room->tunnels = NULL;
	room->type = room_type;
	return (room);
}

int parse_room(game_t *game, e_room_t room_type, char **args)
{
	room_t *room = NULL;

	if (room_type == START && game->start != NULL) {
		my_puterror("lem_in: error: redefinition of starting room: ");
		return (84);
	}
	if (room_type == END && game->end != NULL) {
		my_puterror("lem_in: error: redefinition of ending room: ");
		return (84);
	}
	if ((room = get_default_room(game, room_type, args)) == NULL)
		return (84);
	(game->room_nb) += 1;
	push(&(game->rooms), room);
	if (room_type == START)
		game->start = room;
	if (room_type == END)
		game->end = room;
	return (0);
}