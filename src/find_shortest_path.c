/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** find shortest path
*/

#include "lemin.h"

static void verify_tunnel(l_list_t **list, room_t *data, l_list_t *next)
{
	void *tmp;

	tmp = initialize_list(data, next);
	if (!tmp)
		return;
	push(list, tmp);
	data->marked = true;
}

static void add_other_tunnels(l_list_t **list, l_list_t *cur, l_list_t *sec_cur)
{
	for (sec_cur = sec_cur->next; sec_cur; sec_cur = sec_cur->next) {
		if (!(((room_t *)sec_cur->data)->marked)) {
			verify_tunnel(list, sec_cur->data, \
((l_list_t *)cur->data)->next);
		}
	}
}

static l_list_t *navigate_layer(l_list_t **list)
{
	l_list_t *cur;
	l_list_t *sec_cur;

	for (cur = *list; cur; cur = cur->next) {
		sec_cur = ((room_t *)((l_list_t *)cur->data)->data)->tunnels;
		if (!sec_cur)
			continue;
		for (room_t *r = sec_cur->data; r && r->marked; \
sec_cur = sec_cur->next, r = (room_t *)(sec_cur) ? sec_cur->data : NULL);
		if (sec_cur) {
			push((l_list_t **)&(cur->data), mark_room(sec_cur));
			add_other_tunnels(list, cur, sec_cur);
		}
	}
	return (check_end(*list));
}

static l_list_t *find_first_path(room_t *start, int room_nb)
{
	l_list_t *list = NULL;
	l_list_t *return_tmp = NULL;
	void *tmp;

	tmp = initialize_list(start, NULL);
	if (tmp == NULL)
		return (NULL);
	push(&list, tmp);
	start->marked = true;
	for (int i = 0; i < room_nb; i++) {
		return_tmp = navigate_layer(&list);
		if (return_tmp != NULL)
			return (return_tmp);
	}
	return (NULL);
}

l_list_t *bfs(room_t *start, int room_nb, l_list_t *path_list)
{
	if (!path_list)
		return (find_first_path(start, room_nb));
	return (NULL);
}