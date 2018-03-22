##
## EPITECH PROJECT, 2017
## CPE_lemin_2017
## File description:
## Makefile
##

SRC_DIR		=	$(realpath src)

SRC_FILES	=	global.c		\
			main.c

PARSING_DIR	=	$(realpath src/parsing)

PARSING_FILES	=	parser_main.c					\
			parser_comment_or_command.c			\
			parser_line.c					\
			parser_is.c					\
			parser_is_room_existing.c

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
