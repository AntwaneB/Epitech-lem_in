##
## Makefile for Project Name in /home/buchse_a/
##
## Made by Antoine Buchser
## Login   <buchse_a@epitech.net>
##
## Started on  Mon Apr 14 10:48:43 2014 Antoine Buchser
## Last update Sat May  3 14:50:21 2014 Hugo Schoch
##

NAME		=	lem_in
RM		=	rm -f
CC		=	cc
CFLAGS		=	-Wall -Wextra -g

SRCS		=	main.c \
			get_next_line.c \
			misc.c \
			list_file.c \
			list_rooms.c \
			list_fourmis.c \
			list_bridges.c \
			parsing.c \
			parsing_pattern.c \
			validate.c \
			resolve_lists.c \
			resolve_order.c \
			resolve_get.c \
			resolve.c \
			move_fourmis.c

OBJS		=	$(SRCS:.c=.o)

MY_DIR		=	./libmy

all:			./libmy/libmy.a ${NAME}

./libmy/libmy.a:
			make -C $(MY_DIR)

$(NAME):		$(OBJS)
			$(CC) $(OBJS) -o $(NAME) -lmy -L$(MY_DIR)

clean:
			make clean -C $(MY_DIR)
			$(RM) $(OBJS)

fclean:			clean
			make fclean -C $(MY_DIR)
			$(RM) $(NAME)

re:			fclean all

.SILENT:
