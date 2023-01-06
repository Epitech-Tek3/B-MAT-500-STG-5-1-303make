##
## EPITECH PROJECT, 2021
## 303make
## File description:
## Makefile
##

SRC		=	utils.cpp	\
			help.cpp	\
			main.cpp	\
			processThreeArguments.cpp	\
			processTwoArguments.cpp

CFLAGS	=	-std=c++11 -Wall -Wextra -I include

OBJ		=	$(SRC:.cpp=.o)

INCLUDE	=	-o

LIB		=	-g -lm

NAME	=	303make

all:	$(NAME)

$(NAME):$(OBJ)
	g++ $(OBJ) $(CFLAGS) $(INCLUDE) $(NAME) $(LIB)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re