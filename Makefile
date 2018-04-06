##
## EPITECH PROJECT, 2017
## CPE_lemin_2017
## File description:
## Makefile
##

SRC_DIR		=	$(realpath src)

SRC_FILES	=	global.c		\
			find_shortest_path.c	\
			shortest_path_util.c	\
			main.c			\
			display_moves.c			\
			display.c

PARSING_DIR	=	$(realpath src/parsing)

PARSING_FILES	=	parser_main.c					\
			parser_comment_or_command.c			\
			parser_line.c					\
			parser_is.c					\
			parser_is_room_existing.c			\
			parser_parse_room.c				\
			parser_parse_nb_ant.c				\
			parser_parse_tunnel.c				\
			parser_get_room.c

SRC		=	$(addprefix $(SRC_DIR)/, $(SRC_FILES)) \
			$(addprefix $(PARSING_DIR)/, $(PARSING_FILES))

OBJ		=	$(SRC:%.c=%.o)

NAME		=	lem_in

INCLUDE		=	-I include \
			-I lib/my/include \
			-I lib/mylist/include \

CFLAGS		=	-Wall -Wextra
CFLAGS		+=	$(INCLUDE)

LIB_DIR		=	lib/

LIB_FLAGS	=	-L $(LIB_DIR)my -lmy \
			-L $(LIB_DIR)mylist -lmylist

CC		=	gcc

all:		$(NAME)

$(NAME):	make_lib $(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LIB_FLAGS)

make_lib:
		$(MAKE) -C $(LIB_DIR)my
		$(MAKE) -C $(LIB_DIR)mylist

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

debug:		CFLAGS += -g
debug:		re

tests_run:
		$(MAKE) -C tests/
		./tests/test