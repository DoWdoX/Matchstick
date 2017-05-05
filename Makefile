##
## Makefile for Makefile in /home/DoWdoX/PROJECT/CPE/CPE_2016_matchstick
## 
## Made by DORIAN DEBOUT
## Login   <DoWdoX@epitech.net>
## 
## Started on  Mon Feb 13 10:15:41 2017 DORIAN DEBOUT
## Last update Tue Feb 28 15:12:01 2017 DORIAN DEBOUT
##

CC	=	gcc

NAME	=	matchstick

CFLAGS	+=	-Wall -Wextra

SRCS	=	main.c		\
		functions.c	\
		functions2.c	\
		game2.c		\
		check_line.c	\
		check_end.c	\
		cut_str.c	\
		get_next_line.c	\
		game.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
