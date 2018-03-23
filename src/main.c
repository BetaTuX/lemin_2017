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
	list = bfs(game.start, game.room_nb, NULL);
	if (list == NULL)
		return (ERROR);
	for (l_list_t *cur = list; cur; cur = cur->next) /* DEBUG PURPOSE ONLY*/
		my_printf("%s\n", ((room_t *)cur->data)->name);
	if (display_ants_and_room(&game, list) == ERROR)
		return (ERROR);
	return (0);
}