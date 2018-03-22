/*
** EPITECH PROJECT, 2017
** CPE_lemin_2017
** File description:
** parse a comment or a command
*/

/* File created the 22/03/2018 at 16:33:44 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "my.h"
#include "lemin.h"

int parse_comment_or_command(e_room_t *next_room_type, char **args)
{
	if (args == NULL || my_array_len((void **)args) > 1)
		return (0);
	if (my_strcmp(args[0], "##start") == 0)
		*next_room_type = START;
	if (my_strcmp(args[0], "##end") == 0)
		*next_room_type = END;
	return (0);
}