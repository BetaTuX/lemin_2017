/*
** EPITECH PROJECT, 2017
** lem-in
** File description:
** funct to display ants infos
*/

#include "lemin.h"
#include "my.h"
#include "global.h"

int is_it_start_or_end_room(game_t *game, l_list_t *cursor)
{
	if (game->start != NULL && my_strcmp(((room_t *)cursor->data)->name, \
game->start->name) == 0) {
		my_printf("##start\n%s %i %i\n", game->start->name, \
game->start->pos.x, game->start->pos.y);
		return (1);
	}
	if (game->end != NULL && my_strcmp(((room_t *)cursor->data)->name, \
game->end->name) == 0) {
		my_printf("##end\n%s %i %i\n", game->end->name, \
game->end->pos.x, game->end->pos.y);
		return (1);
	}
	return (0);
}

int display_ants_and_room(game_t *game, l_list_t *path)
{
	l_list_t *cursor = game->rooms;

	my_printf("#number_of_ants\n%i\n#rooms\n", game->ant_nb);
	for (; cursor != NULL; cursor = cursor->next) {
		if (is_it_start_or_end_room(game, cursor) != 1)
			my_printf("%s %i %i\n", ((room_t *)cursor->data)->\
name, ((room_t *)cursor->data)->pos.x, ((room_t *)cursor->data)->pos.y);
	}
	my_putstr("#tunnels\n");
	for (cursor = game->tunnels; cursor != NULL; cursor = cursor->next) {
		my_printf("%s\n", (char *)cursor->data);
	}
	my_putstr("#moves\n");
	if (path != NULL)
		print_moves(game, path);
	return (0);
}