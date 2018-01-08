/*
** move_down_plat.c for tetris in /home/chauvi_d/Rendu-2015-Epitech/rendu/Systunix/PSU_2015_tetris/game
** 
** Made by chauvi_d
** Login   <chauvi_d@epitech.net>
** 
** Started on  Tue Mar 15 15:21:52 2016 chauvi_d
** Last update Thu Mar 17 15:29:48 2016 Arthur Chennetier
*/

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <curses.h>
#include "map.h"
#include "my.h"

int	move_down_plat(t_game *ctx, int i, int j)
{
  int	x;
  int	down;

  x = i + j;
  j = j;
  if (i >= 0 && i <= ctx->keys->col)
    return (0);
  while (x != 0)
    {
      down = x - ctx->keys->col;
      if (ctx->game[x] ==  ' ' && ctx->game[down] == '*')
	{
	  ctx->game[x] = '*';
	  ctx->color[x] = ctx->color[down];
	  ctx->game[down] = ' ';
	}
      x = x - 1;
    }
  return (0);
}

int		check_under_tetri(t_game *ctx)
{
  int		y;
  int		tmp;
  int		i;
  int		j;

  return (0);
  i = 0;
  j = ctx->var->tetrimino.height - 1;
  y = ctx->idx + (ctx->var->tetrimino.height * ctx->keys->col);
  tmp = y;
  while (y < tmp + ctx->var->tetrimino.width)
    {
      if (ctx->color[y] != -1 && ctx->var->tetrimino.piece[j][i] == '*')
	return (-1);
      i = i + 1;
      y = y + 1;
    }
  return (0);
}
