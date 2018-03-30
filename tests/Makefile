##
## EPITECH PROJECT, 2017
## CPE_lemin
## File description:
## Makefile for unit tests
##

SRC_DIR		=	$(realpath ../src)

SRC_FILES	=

PARSING_DIR	=	$(realpath ../src/parsing)

PARSING_FILES	=	parser_main.c					\
			parser_comment_or_command.c			\
			parser_line.c					\
			parser_is.c					\
			parser_is_room_existing.c			\
			parser_parse_room.c				\
			parser_parse_nb_ant.c				\
			parser_parse_tunnel.c				\
			parser_get_room.c

SRC		=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))\
			$(addprefix $(PARSING_DIR)/, $(PARSING_FILES))

TESTS_DIR	=	$(realpath ./src)

TESTS_FILES	=	tests_parser.c

SRC_TESTS	=	$(addprefix $(TESTS_DIR)/, $(TESTS_FILES))

OBJ		=	$(SRC:%.c=%.o) $(SRC_TESTS:%.c=%.o)

CCTMP		=	$(SRC:%.c=%.gcno) $(SRC:%.c=%.gcda) $(SRC_TESTS:%.c=%.gcno) $(SRC_TESTS:%.c=%.gcda)

NAME		=	test

INCLUDE		=	-I ../include -I ../lib/my/include -I ../lib/mylist/include

CFLAGS		=	-Wall -Wextra --coverage
CFLAGS		+=	$(INCLUDE)

LIB_DIR		=	../lib/

LIB_FLAGS	=	-L $(LIB_DIR)my -L $(LIB_DIR)mylist -lmy -lmylist -lcriterion -lgcov

LIB		=	$(LIB_DIR)my/libmy.a

CC		=	gcc

all:		$(NAME)

$(NAME):	$(LIB)
		$(CC) -o $(NAME) $(SRC) $(SRC_TESTS) $(LIB_FLAGS) $(CFLAGS)

$(LIB):
		$(MAKE) -C $(LIB_DIR)my
		$(MAKE) clean -C $(LIB_DIR)my

cclean:
		$(RM) $(CCTMP)
		$(RM) *.gcno
		$(RM) *.gcda
		$(RM) *.gcov

clean:		cclean
		$(RM) $(OBJ)

fclean:		clean
		$(RM) -f $(NAME)

re:		fclean all