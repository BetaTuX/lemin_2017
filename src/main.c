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
	game_t game = {0, 0, NULL, NULL, NULL, NULL};
	l_list_t *list = NULL;

	if (fill_game(&game))
		return (ERROR);
	if (!(game.start == NULL || game.end == NULL))
		list = bfs(game.start, game.room_nb, NULL);
	if (list == NULL)
		return (ERROR);
	if (display_ants_and_room(&game, list) == ERROR)
		return (ERROR);
	return (0);
}