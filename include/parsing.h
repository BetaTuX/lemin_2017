/*
** EPITECH PROJECT, 2017
** CPE_lemin_2017
** File description:
** Parsing header
*/

/* File created the 22/03/2018 at 15:41:26 by julian.frabel@epitech.eu */

#ifndef __LEMIN_PARSER_H_
	#define __LEMIN_PARSER_H_

	#include "lemin.h"

	int fill_game(game_t *game);

	bool is_nb_ant(char **args);
	bool is_room(char **args);
	bool is_tunnel(char **args);

	int does_name_already_exist(game_t *game, char *name);

	room_t *get_room_by_name(game_t *game, const char *name);

	int parse_comment_or_command(e_room_t *next_room_type, char **args);
	int parse_line(game_t *game, char **args, e_room_t *next_room_type);

	int parse_room(game_t *game, e_room_t room_type, char **args);
	int parse_nb_ant(game_t *game, char **args);
	int parse_tunnel(game_t *game, char **args);

#endif /* !__LEMIN_PARSER_H_ */