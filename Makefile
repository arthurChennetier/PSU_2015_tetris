##
## Makefile for BSQ in /home/chauvi_d/rendu/Prog_Elem/CPE_2015_BSQ
## 
## Made by Chauvin Antoine
## Login   <chauvi_d@epitech.net>
## 
## Started on  Mon Dec  7 14:19:51 2015 Chauvin Antoine
## Last update Sun Mar 20 18:46:40 2016 Arthur Chennetier
##

CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-W -Werror -Wextra -Wall -I./ -I./include

LDFLAGS	=	-lncurses -L./lib/my -lmy -L./lib/get_next_line

NAME	=	tetris

SRCS	=	main.c \
		my_free.c \
		./options/options.c \
		./options/fct_options.c \
		./options/fct_key.c \
		./options/keybind.c \
		./options/termcap.c \
		./options/fct_tetriminos.c \
		./options/print_tetriminos.c \
		./options/level_change.c \
		./map/letters.c \
		./map/map.c \
		./map/display_windows.c \
		./map/display_windows2.c \
		./map/read_tetrimino.c \
		./map/test_tetrimino.c \
		./map/second_test_tetrimino.c \
		./map/time.c \
		./game/game.c \
		./game/user_key.c \
		./game/init_game.c \
		./game/move_check_tetri.c \
		./game/turn_move.c \
		./game/move_down_plat.c \
		./game/get_high_score.c \
		./game/delay_passed.c \
		./game/check_err.c

OBJS	=	$(SRCS:.c=.o)


all:	$(NAME)

$(NAME): $(OBJS)
	make -C ./lib/my/src
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)


clean:
	$(RM) $(OBJS)
	make clean -C ./lib/my/src

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./lib/my/src

re: 	fclean all
