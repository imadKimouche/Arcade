##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## This is the Makefile
##

SRC	=	./src/SnakeGame.cpp \
		./src/SnakeHead.cpp \
		./src/SnakeBody.cpp \
		./src/main.cpp \
		./src/Food.cpp \
		./src/Board.cpp \
		../AObject.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	snake-debug

$(LFLAG): 	-Wfatal-errors -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):
		g++ -I include/ -o $(NAME) $(LFLAG) $(SRC)

clean:
	rm -rf *.o
	rm -rf *~
	rm -rf *#

fclean: clean
	rm -rf $(NAME)

re: fclean all $(NAME)
