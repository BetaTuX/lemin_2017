/*
** EPITECH PROJECT, 2017
** CPE_lemin
** File description:
** Test the parser
*/

/* File created the 30/03/2018 at 15:12:54 by julian.frabel@epitech.eu */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "parsing.h"

void redirect_stdin(void)
{
	int fd = open("tests/anthill/anthill_tester", O_RDONLY);

	dup2(fd, 0);
}

/*
3
##start
0 1 0
##end
1 13 0 #bedroom
2 5 0
# The next room is the kitchen
3 9 0
0-2
2-3
3-1
*/
Test(parser_main, all_valid_map, .timeout=10, .init=redirect_stdin)
{
	game_t game = {0, 0, NULL, NULL, NULL, NULL};

	cr_expect(fill_game(&game) == 0);
	cr_expect(game.ant_nb == 3);
	cr_expect(game.room_nb == 4);
	cr_expect_str_eq(game.start->name, "0");
	cr_expect(game.start->pos.x == 1);
	cr_expect(game.start->pos.y == 0);
	cr_expect_str_eq(game.end->name, "1");
	cr_expect(game.end->pos.x == 13);
	cr_expect(game.end->pos.y == 0);
	cr_expect_str_eq(game.tunnels->data, "0-2");
}