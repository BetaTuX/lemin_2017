/*
** EPITECH PROJECT, 2017
** CPE_lemin_2017
** File description:
** Parse a tunnel
*/

/* File created the 22/03/2018 at 18:35:27 by julian.frabel@epitech.eu */

#include <stdbool.h>
#include <stdlib.h>
#include "my.h"
#include "match.h"
#include "lemin.h"
#include "parsing.h"

static int connect(room_t *first_room, room_t *second_room, \
game_t *game, char *names[2])
{
	int tunnel_char_size = my_strlen(names[0]) + my_strlen(names[1]) + 1;
	char *tunnel = malloc(sizeof(*tunnel) * (tunnel_char_size + 1));

	if (tunnel == NULL) {
		my_puterror("lem_in: system error: malloc failed: ");
		return (84);
	}
	for (int i = 0; i < tunnel_char_size; i++)
		tunnel[i] = 0;
	my_strcat(tunnel, names[0]);
	my_strcat(tunnel, "-");
	my_strcat(tunnel, names[1]);
	push(&(game->tunnels), tunnel);
	if (my_strcmp(names[0], names[1]) != 0 && first_room && second_room) {
		push(&(first_room->tunnels), second_room);
		push(&(second_room->tunnels), first_room);
	}
	return (0);
}

static int parse_tunnel_1(game_t *game, char **args)
{
	char *cut[2];
	room_t *first_room = NULL;
	room_t *second_room = NULL;
	int i = 0;

	cut[0] = args[0];
	for (i = 0; args[0][i] != '-'; i++);
	args[0][i] = '\0';
	cut[1] = &(args[0][i + 1]);
	first_room = get_room_by_name(game, cut[0]);
	second_room = get_room_by_name(game, cut[1]);
	if (first_room == NULL || second_room == NULL) {
		my_puterror("lem_in: error: Unknown room: ");
	}
	return (connect(first_room, second_room, game, cut));
}

static int parse_tunnel_2(game_t *game, char **args)
{
	room_t *first_room = NULL;
	room_t *second_room = NULL;

	if (args[0][my_strlen(args[0]) - 1] == '-')
		args[0][my_strlen(args[0]) - 1] = '\0';
	else
		for (int i = 1; args[1][i]; i++)
			args[1][i - 1] = args[1][i];
	first_room = get_room_by_name(game, args[0]);
	second_room = get_room_by_name(game, args[1]);
	if (first_room == NULL || second_room == NULL) {
		my_puterror("lem_in: error: Unknown room: ");
	}
	return (connect(first_room, second_room, game, args));
}

static int parse_tunnel_3(game_t *game, char **args)
{
	char *names[2] = {args[0], args[2]};
	room_t *first_room = NULL;
	room_t *second_room = NULL;

	first_room = get_room_by_name(game, names[0]);
	second_room = get_room_by_name(game, names[1]);
	if (first_room == NULL || second_room == NULL) {
		my_puterror("lem_in: error: Unknown room: ");
	}
	return (connect(first_room, second_room, game, names));
}

int parse_tunnel(game_t *game, char **args)
{
	switch (my_array_len((void **)args)) {
	case 1: return (parse_tunnel_1(game, args));
	case 2: return (parse_tunnel_2(game, args));
	case 3: return (parse_tunnel_3(game, args));
	}
	return (0);
}