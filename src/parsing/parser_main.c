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
#include "parsing.h"

void reverse_linked_lists(game_t *game)
{
	my_rev_list(&(game->rooms));
	my_rev_list(&(game->tunnels));
}

int check_rooms_validity(game_t *game)
{
	(void)game;
	return (0);
}

void display_line_error(int line_pos, char *line)
{
	char *int_str = my_int_to_str(line_pos);

	my_puterror(line);
	my_puterror(" at position: ");
	my_puterror(int_str);
	my_puterror("\n");
	free(int_str);
}

int fill_game(game_t *game)
{
	char *next_line = NULL;
	char **args = NULL;
	e_room_t next_room_type = 0;

	next_line = get_next_line(0);
	for (int i = 1; next_line != NULL; i++) {
		args = my_parse_str_to_array(next_line, " \t", "", "");
		if (next_line[0] == '#')
			parse_comment_or_command(&next_room_type, args);
		else if (parse_line(game, args, next_room_type)) {
			display_line_error(i, next_line);
			my_free_array((void **)args);
			free(next_line);
			return (84);
		}
		my_free_array((void **)args);
		free(next_line);
		next_line = get_next_line(0);
	}
	reverse_linked_lists(game);
	return (check_rooms_validity(game));
}