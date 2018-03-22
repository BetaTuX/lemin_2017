/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** lemin header
*/

#ifndef LEMIN_H_
	#define LEMIN_H_

	typedef struct s_graph_node {
		int id;
		linked_list_t *connected;
	} graph_t;
#endif