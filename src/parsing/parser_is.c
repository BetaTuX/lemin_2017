/*
** EPITECH PROJECT, 2017
** CPE_lemin_2017
** File description:
** Function that return if arguments are a type
*/

/* File created the 22/03/2018 at 17:29:59 by julian.frabel@epitech.eu */

#include <stdbool.h>
#include <stdlib.h>
#include "my.h"
#include "match.h"
#include "lemin.h"

bool is_nb_ant(char **args)
{
	if (my_array_len((void **)args) != 1)
		return (false);
	if (my_str_isnum(args[0]) && my_getnbr(args[0]) != 0)
		return (true);
	return (false);
}

bool is_room(char **args)
{
	if (my_array_len((void **)args) != 3)
		return (false);
	if (!my_str_isnum(args[1]) || !my_str_isnum(args[2]))
		return (false);
	return (true);
}

bool is_tunnel(char **args)
{
	int nb_args = my_array_len((void **)args);

	if (nb_args > 3)
		return (false);
	switch (nb_args) {
	case 1:
		if (match(args[0], "*-*"))
			return (true);
		break;
	case 2:
		if (match(args[0], "*-") || match(args[1], "-*"))
			return (true);
		break;
	case 3:
		if (!my_strcmp(args[1], "-"))
			return (true);
		break;
	}
	return (false);
}