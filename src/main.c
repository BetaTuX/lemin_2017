/*
** EPITECH PROJECT, 2018
** Lem-in 2017
** File description:
** lemin main fx
*/

#include "my.h"
#include "lemin.h"
#include "global.h"
#include "parsing.h"

int main(UNUSED int argc, UNUSED char **argv)
{
	game_t game = {0, NULL, NULL};

	if (fill_game(&game))
		return (ERROR);
	return (0);
}