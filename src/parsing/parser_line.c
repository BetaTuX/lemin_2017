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

int parse_line(game_t *game, char **args, e_room_t *next_room_type)
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
	if (is_room(data) && parse_room(game, *next_room_type, args))
		return (84);
	if (is_tunnel(data) && parse_tunnel(game, args))
		return (84);
	*next_room_type = DEFAULT;
	return (0);
}