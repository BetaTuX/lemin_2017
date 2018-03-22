/*
** EPITECH PROJECT, 2017
** CPE_lemin_2017
** File description:
** main file for the parsing
*/

/* File created the 22/03/2018 at 15:44:15 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "my.h"
#include "lemin.h"

int parse_comment_or_command(e_room_t *next_room_type, char **args)
{
	return (0);
}

int parse_line(game_t *game, char **args, e_room_t next_room_type)
{
	return (0);
}

int fill_game(game_t *game)
{
	char *next_line = NULL;
	char **args = NULL;
	e_room_t next_room_type = 0;

	next_line = get_next_line(0);
	while (next_line != NULL) {
		args = my_parse_str_to_array(next_line, " \t", "", "");
		if (next_line[0] == '#')
			parse_comment_or_command(&next_room_type, args);
		if (parse_line(game, args, next_room_type)) {
			my_free_array((void **)args);
			free(next_line);
			return (84);
		}
		my_free_array((void **)args);
		free(next_line);
		next_line = get_next_line(0);
	}
	return (0);
}