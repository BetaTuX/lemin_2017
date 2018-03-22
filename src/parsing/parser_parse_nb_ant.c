/*
** EPITECH PROJECT, 2017
** CPE_lemin_2017
** File description:
** Parse the number of ants
*/

/* File created the 22/03/2018 at 18:34:01 by julian.frabel@epitech.eu */

#include <stdbool.h>
#include <stdlib.h>
#include "my.h"
#include "match.h"
#include "lemin.h"
#include "parsing.h"

int parse_nb_ant(game_t *game, char **args)
{
	if (game->ant_nb != 0) {
		my_puterror("lem_in: error: redefinition of ant number: ");
		return (84);
	}
	game->ant_nb = my_getnbr(args[0]);
	return (0);
}