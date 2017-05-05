##
## Makefile for Makefile in /home/DoWdoX/PROJECT/CPE/CPE_2016_matchstick
## 
## Made by DORIAN DEBOUT
## Login   <DoWdoX@epitech.net>
## 
## Started on  Mon Feb 13 10:15:41 2017 DORIAN DEBOUT
## Last update Fri May  5 18:11:19 2017 DORIAN DEBOUT
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

CC	=	gcc

RM	=	rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
