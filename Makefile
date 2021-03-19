##
## EPITECH PROJECT, 2020
## Makefile du main
## File description:
## le make lance tout le projet
##

CC = gcc -o

SRC	=	sources/main.c					\
		sources/sokoban.c				\
		sources/move.c				\
		sources/smallfunctions.c 		\
		sources/my_str_to_word_array.c	\

OBJ	=	$(SRC)

NAME	=	my_sokoban

all:		$(NAME)

$(NAME):
		make -C lib/my
		$(CC) $(NAME) $(SRC) -I./include -L./lib -lmy -lm -lcurses -l csfml-audio

clean:
		make -C lib/my clean

fclean:
		make -C lib/my fclean
		rm $(NAME)
		clear

re:		fclean all
