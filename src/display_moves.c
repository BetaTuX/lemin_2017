/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** display ant moves
*/

#include <unistd.h>
#include "my.h"
#include "mylist.h"
#include "lemin.h"

static char *name_at(l_list_t *list, int index)
{
	l_list_t *cur = list_at(list, index);

	if (cur)
		return (((room_t *)cur->data)->name);
	else
		return ("");
}

static void display_before(l_list_t *path, int path_len, int i)
{
	for (int j = 0; j < i + 1; j++)
		my_printf("P%d-%s ", j + 1, \
name_at(path, path_len - (i - j + 1)));
	write(1, "\n", 1);
}

static void display_body(l_list_t *path, int path_len, int i)
{
	for (int j = path_len; 0 < j; j--)
		my_printf("P%d-%s ", i - (j - 2), name_at(path, path_len - j));
	write(1, "\n", 1);
}

static void display_after(l_list_t *path, int path_len, int ant_nb)
{
	for (int c = path_len - 2; 0 <= c; c--) {
		for (int j = 0; j < c + 1; j++)
			my_printf("P%d-%s ", ant_nb - c + j, \
	name_at(path, j));
		write(1, "\n", 1);
	}
}

void print_moves(game_t *game, l_list_t *path)
{
	int path_len = my_list_size(path) - 1;
	int ant_nb = game->ant_nb;

	path = path->next;
	my_rev_list(&path);
	for (int i = 0; 1; i++) {
		if (i < path_len) {
			display_before(path, path_len, i);
			continue;
		} else if (i < ant_nb) {
			display_body(path, path_len, i);
			continue;
		} else
			display_after(path, path_len, ant_nb);
		break;
	}
}