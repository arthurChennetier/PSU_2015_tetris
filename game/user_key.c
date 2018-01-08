/*
** user_key.c for tetris in /home/chauvi_d/Rendu-2015-Epitech/rendu/Systunix/PSU_2015_tetris/game
** 
** Made by chauvi_d
** Login   <chauvi_d@epitech.net>
** 
** Started on  Thu Mar 10 17:28:28 2016 chauvi_d
** Last update Thu Mar 17 17:28:56 2016 chauvi_d
*/

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <curses.h>
#include "map.h"
#include "my.h"

int	left_move(t_game *ctx)
{
  if ((ctx->idx) % ctx->keys->col != 0)
    {
      if (clear_tetri(ctx) == -1)
	return (-1);
      if (check_tetri(ctx, ctx->idx - 1) != -1)
	ctx->idx = ctx->idx - 1;
      else
	{
	  add_tetri(ctx);
	  return (-1);
	}
      if (add_tetri(ctx) == -1)
	return (-1);
    }
  return (0);
}

int	right_move(t_game *ctx)
{
  if ((ctx->idx + ctx->var->tetrimino.width) % ctx->keys->col != 0)
    {
      if (clear_tetri(ctx) == -1)
	return (-1);
      if (check_tetri(ctx, ctx->idx + 1) != -1)
	ctx->idx = ctx->idx + 1;
      else
	{
	  add_tetri(ctx);
	  return (-1);
	}
      if (add_tetri(ctx) == -1)
	return (-1);
    }
  return (0);
}

int	down_move(t_game *ctx)
{
  if (ctx->idx + ctx->var->tetrimino.height * ctx->keys->col
      < ctx->keys->row * ctx->keys->col)
    {
      if (clear_tetri(ctx) == -1)
	  return (-1);
      if (check_tetri(ctx, ctx->idx + ctx->keys->col) != -1)
	ctx->idx = ctx->idx + ctx->keys->col;
      else
	{
	  add_tetri(ctx);
      	  return (-1);
	}
      if (add_tetri(ctx) == -1)
	return (-1);
    }
  return (0);
}

int		key_pause(t_game *ctx)
{
  int		i;
  time_t	t;

  buff[0] = 0;
  while (my_strcmp(buff, ctx->keys->kp) != 0)
    {
      if ((i = read(0, buff, 10)) == -1)
	return (-1);
      buff[i] = 0;
    }
  t = time(&t);
  ctx->var->time = t;
  return (0);
}

int	user_key(t_game *ctx)
{
  if (my_strcmp(buff, ctx->keys->kl) == 0)
    left_move(ctx);
  if (my_strcmp(buff, ctx->keys->kr) == 0)
    right_move(ctx);
  if (my_strcmp(buff, ctx->keys->kd) == 0 &&
      check_under_tetri(ctx) == 0)
    down_move(ctx);
  if (my_strcmp(buff, ctx->keys->kp) == 0)
    key_pause(ctx);
  if (my_strcmp(buff, ctx->keys->kt) == 0)
    turn_move(ctx);
  return (0);
}
