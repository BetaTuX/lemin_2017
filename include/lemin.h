/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** lemin header
*/

#ifndef LEMIN_H_
	#define LEMIN_H_

	#include "mylist.h"

	typedef struct s_graph_node {
		int id;
		l_list_t *connected;
	} graph_t;
#endif