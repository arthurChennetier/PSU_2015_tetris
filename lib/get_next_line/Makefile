##
## Makefile for Makefile in /home/chenne_a/rendu/Piscine_C_J10/lib/my
## 
## Made by Arthur Chennetier
## Login   <chenne_a@epitech.net>
## 
## Started on  Fri Oct  9 10:38:18 2015 Arthur Chennetier
## Last update Fri Feb 12 12:36:56 2016 Arthur Chennetier
##

SRC	= get_next_line.c

RM	= rm -f

OBJ	= $(SRC:.c=.o)

CC	= gcc

TEMP	= $(SRC:.c=.c~)

MLIB	= ar rc

NAME	= libgnl.a

PREP	= ranlib


all: $(NAME)

$(NAME):	$(OBJ)
	$(MLIB) $(NAME) $(OBJ)
	$(PREP) $(NAME)

clean: 
	$(RM) $(OBJ)
	$(RM) $(TEMP)

fclean:		clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
