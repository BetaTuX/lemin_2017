/*
** EPITECH PROJECT, 2017
** List lib
** File description:
** Lib header
*/

#ifndef __BTA_LIST_H_
#define __BTA_LIST_H_

#include <stdlib.h>

#ifndef NULL
	#define NULL ((void *)0)
#endif

typedef struct node {
	void *data;
	struct node *next;
} l_list_t;

typedef l_list_t l_dict_t;

int my_apply_on_nodes(l_list_t *begin, int (*f)(void *));
void my_concat_list(l_list_t **list1, l_list_t *list2);
int my_delete_nodes(l_list_t **list, void const *data_ref, int (*cmp)());
int my_list_size(l_list_t const *list);
int my_rev_list(l_list_t **list);
void my_sort_list(l_list_t **list, int (*cmp)());
l_list_t *list_at(l_list_t *list, int ind);
void push(l_list_t **list, void *elem);
void append(l_list_t **list, void *elem);
void *pop(l_list_t **list);
void dict_add(l_dict_t **dict, char *label, void *data);
void *dict_fetch(l_dict_t *dict, char *label);
void dict_destroy(l_dict_t *dict);
l_list_t *list_at(l_list_t *list, int ind);

/* fx description:
** initialize a new l_list_t with an initial value
*/
static inline l_list_t *initialize_list(void *data, l_list_t *next)
{
	l_list_t *list = malloc(sizeof(*list));

	if (!list)
		return (NULL);
	list->data = data;
	list->next = next;
	return (list);
}

	#define DICT_RET(Fx_name, Type, ...) \
	\
		static Type Fx_name(l_list_t *list) \
		{ \
			return (*(Type *)list->data); \
		}

#endif