/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** find shortest path
*/

#include "lemin.h"

l_list_t *find_first_path(room_t *start, int room_nb)
{
	l_list_t *list = NULL;
	l_list_t *cur;
	l_list_t *sec_cur;

	push(&list, initialize_list(start, NULL));
	start->marked = true;
	// for (l_list_t *bit = list; bit; bit = bit->next, my_printf("next\n"))
	// 	for (l_list_t *tib = bit->data; tib; tib = tib->next)
	// 		my_printf("%s\n", ((room_t *)tib->data)->name);
	// my_printf("end\n");
	for (int i = 0; i < room_nb; i++) {
		for (cur = list; cur; cur = cur->next) {
			sec_cur = ((room_t *)((l_list_t *)cur->data)->data)->tunnels;
			for (room_t *r = sec_cur->data; r && r->marked; \
sec_cur = sec_cur->next, r = (room_t *)(sec_cur) ? sec_cur->data : NULL);
			if (sec_cur && !((room_t *)sec_cur->data)->marked) { /* Useless second condition */
				push((l_list_t **)&(cur->data), sec_cur->data);
				((room_t *)sec_cur->data)->marked = true;
				for (sec_cur = sec_cur->next; sec_cur; sec_cur = sec_cur->next) {
					if (!(((room_t *)sec_cur->data)->marked)) {
						push(&list, initialize_list(sec_cur->data, ((l_list_t *)cur->data)->next));
						((room_t *)sec_cur->data)->marked = true;
					}
				}
			}
			// for (l_list_t *bit = list; bit; bit = bit->next, my_printf("next\n"))
				// for (l_list_t *tib = bit->data; tib; tib = tib->next)
					// my_printf("%s\n", ((room_t *)tib->data)->name);
			// my_printf("end\n");
			// my_printf("\"%s\" type : %d\n", ((room_t *)((l_list_t *)cur->data)->data)->name, ((room_t *)((l_list_t *)cur->data)->data)->type);
			if (cur && cur->data && ((l_list_t *)cur->data)->data && ((room_t *)((l_list_t *)cur->data)->data)->type == END) {
				my_rev_list((l_list_t **)&(cur->data));
				return ((l_list_t *)cur->data);
			}
		}
	}
	return (NULL);
}

l_list_t *bfs(room_t *start, int room_nb, l_list_t *path_list)
{
	if (!path_list)
		return (find_first_path(start, room_nb));
	return (NULL);
}