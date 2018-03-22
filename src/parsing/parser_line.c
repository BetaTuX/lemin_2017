/*
** EPITECH PROJECT, 2017
** CPE_lemin_2017
** File description:
** Parse a given line
*/

/* File created the 22/03/2018 at 16:31:59 by julian.frabel@epitech.eu */

#include <stdbool.h>
#include <stdlib.h>
#include "my.h"
#include "match.h"
#include "lemin.h"
#include "parsing.h"

room_t *get_default_room(game_t *game, e_room_t room_type, char **args)
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

int parse_nb_ant(game_t *game, char **args)
{
	if (game->ant_nb != 0) {
		my_puterror("lem_in: error: redefinition of ant number: ");
		return (84);
	}
	game->ant_nb = my_getnbr(args[0]);
	return (0);
}

int parse_line(game_t *game, char **args, e_room_t next_room_type)
{
	char *data[my_array_len((void **)args) + 1];

	for (int i = 0; args[i] != NULL && args[i][0] != '#'; i++) {
		data[i] = args[i];
		data[i + 1] = NULL;
	}
	if (!is_nb_ant(data) && !is_room(data) && !is_tunnel(data)) {
		my_puterror("lem_in: error: invalid line: ");
		return (84);
	}
	if (is_nb_ant(data) && parse_nb_ant(game, data))
		return (84);
	if (is_room(data) && parse_room(game, next_room_type, args))
		return (84);
	return (0);
}