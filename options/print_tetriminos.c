/*
** print_tetriminos.c for tetris in /home/chenne_a/rendu/semestre2/PSU_2016/PSU_2015_tetris/options
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Tue Mar  8 16:15:18 2016 Arthur Chennetier
** Last update Thu Mar 17 17:34:01 2016 Arthur Chennetier
*/

#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "my.h"

void		print_piece(char **piece)
{
  int		i;
  int		y;

  i = 0;
  while (piece[i] != NULL)
    {
      y = my_strlen(piece[i]);
      while (piece[i][y - 1] == ' ')
	y = y - 1;
      if (y != my_strlen(piece[i]))
	piece[i][y] = '\0';
      my_putstr(piece[i]);
      my_putchar('\n');
      i = i + 1;
    }
}

void		print_tetriminos(t_tetris *piece, int *order, int size)
{
  int		i;
  int		y;
  int		stop;

  i = 0;
  my_printf("Tetriminos : %i\n", size);
  while (i < size)
    {
      y = order[i];
      my_printf("Tetriminos : Name ");
      stop = my_strlen(piece[y].name);
      piece[y].name[stop - 10] = '\0';
      if (piece[y].width == 0 || piece[y].height == 0
	  || piece[y].color == 0 || piece[y].piece == NULL)
	my_printf("%s : Error\n", piece[y].name);
      else
	{
	  my_printf("%s : Size %i*%i : Color %i :\n",
		    piece[y].name, piece[y].width,
		    piece[y].height, piece[y].color);
	  print_piece(piece[y].piece);
	}
      i = i + 1;
    }
}
