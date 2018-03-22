/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** lemin header
*/

#ifndef LEMIN_H_
	#define LEMIN_H_

	#include "mylist.h"

	typedef enum e_room_type {
		DEFAULT = 0,
		START = 1,
		END = 2
	} e_room_t;

	typedef struct s_vector2i {
		int x;
		int y;
	} vector2i_t;

	typedef struct s_room {
		char *name;
		vector2i_t pos;
		e_room_t type;
		l_list_t *route;
	} room_t;

	typedef struct s_game {
		int ant_nb;
		l_list_t *rooms;
		l_list_t *tunnels;

	} game_t;

	find_shortest_path();
#endif