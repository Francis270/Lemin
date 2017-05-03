##
## Makefile for lemin in /home/francis/Documents/CPE/CPE_2016_Lem-In/
##
## Made by Francois Caicedo
## Login   <francois.caicedo@epitech.eu@epitech.eu>
##
## Started on  Sat Apr  1 22:44:44 2017 Francois Caicedo
## Last update Sun Apr 30 19:32:47 2017 Francois Caicedo
##

NAME		= lem_in

SRCS		= main.c						\
		  parsing/map_parser.c					\
		  parsing/parse_rooms_line.c				\
		  parsing/parse_path_line.c				\
		  parsing/list.c					\
		  parsing/setup_matrix.c				\
		  parsing/get_name_path.c				\
		  algo/start.c						\
		  algo/display.c					\
		  algo/display_special_case.c				\
		  algo/free.c						\
		  lib/my_1dc_comps.c					\
		  lib/my_1dc_utils.c					\
		  lib/my_1dcn_utils.c					\
		  lib/my_2dc_utils.c					\
		  lib/my_gets.c						\
		  lib/my_lenghts.c					\
		  lib/my_puts.c						\
		  lib/my_reallocs.c					\
		  lib/my_xlib.c

OBJS		= $(addprefix src/, $(SRCS:.c=.o))

CC		= gcc

RM		= rm -f

CFLAGS		= -Iinclude/			\
 		-W -Wall -Wextra -Werror	\
		-Wno-unused-parameter		\
 		-ansi -pedantic			\
 		$(LIBS)

LDFLAGS		= $(LIBS)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

all:		$(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
