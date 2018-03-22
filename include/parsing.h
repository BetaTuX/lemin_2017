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

	int parse_comment_or_command(e_room_t *next_room_type, char **args);
	int parse_line(game_t *game, char **args, e_room_t next_room_type);

#endif /* !__LEMIN_PARSER_H_ */