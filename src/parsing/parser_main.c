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

int fill_game(game_t *game)
{
	char *next_line = NULL;

	next_line = get_next_line(0);
	while (next_line != NULL) {

		next_line = get_next_line(0);
	}
	return (0);
}