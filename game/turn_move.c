/*
** turn_move.c for tetris in /home/chenne_a/rendu/semestre2/PSU_2016/PSU_2015_tetris/game
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Tue Mar 15 14:36:47 2016 Arthur Chennetier
** Last update Thu Mar 17 16:58:34 2016 Arthur Chennetier
*/

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <curses.h>
#include "map.h"
#include "my.h"

int		init_turn(t_turn *var, t_game *ctx)
{
  if ((var->tmp = malloc(sizeof(char*) *
		    (ctx->var->tetrimino.width + 1))) == NULL)
    return (-1);
  var->i = 0;
  while (var->i < ctx->var->tetrimino.width)
    {
      if ((var->tmp[var->i] =
	   malloc(sizeof(char) * (ctx->var->tetrimino.height + 1))) == NULL)
	return (-1);
      var->i = var->i + 1;
    }
  var->tmp[var->i] = NULL;
  var->i = 0;
  var->x = 0;
  return (0);
}

char		**my_double_strcpy(char **src)
{
  char		**dest;
  int		i;

  i = 0;
  while (src[i] != NULL)
    i = i + 1;
  dest = malloc(sizeof(char*) * (i + 1));
  dest[i] = NULL;
  i = 0;
  while (src[i] != NULL)
    {
      dest[i] = malloc(sizeof(char) * (my_strlen(src[i]) + 1));
      my_strcpy(dest[i], src[i]);
      i = i + 1;
    }
  return (dest);
}

int		turn_change_param(t_turn *var, t_game *ctx)
{
  int		tmp;

  ctx->var->tetrimino.piece = my_double_strcpy(var->tmp);
  tmp = ctx->var->tetrimino.width;
  ctx->var->tetrimino.width = ctx->var->tetrimino.height;
  ctx->var->tetrimino.height = tmp;
  check_tetri(ctx, ctx->idx);
  clear_tetri(ctx);
  add_tetri(ctx);
  return (0);
}

int		turn_check(t_game *ctx)
{
  int		tmp;

  tmp = ctx->var->tetrimino.height;
  if ((ctx->idx + ctx->var->tetrimino.height - 1) %
      ctx->keys->col >= ctx->var->tetrimino.height
      || ctx->idx % ctx->keys->col == 0)
    {
      if (clear_tetri(ctx) == -1)
	return (-1);
      ctx->var->tetrimino.height = ctx->var->tetrimino.width;
      ctx->var->tetrimino.width = tmp;
      if (check_tetri(ctx, ctx->idx) != -1)
	{
	  tmp = ctx->var->tetrimino.height;
	  ctx->var->tetrimino.height = ctx->var->tetrimino.width;
	  ctx->var->tetrimino.width = tmp;
	  return (0);
	}
      else
	return (-1);
    }
  return (-1);
}

int		turn_move(t_game *ctx)
{
  t_turn	*var;

  if ((var = malloc(sizeof(t_turn))) == NULL)
    return (-1);
  if (init_turn(var, ctx) == -1)
    return (-1);
  while (var->i < ctx->var->tetrimino.width)
    {
      var->y = ctx->var->tetrimino.height - 1;
      var->j = 0;
      while (var->j < ctx->var->tetrimino.height)
	{
	  var->tmp[var->i][var->j] =
	    ctx->var->tetrimino.piece[var->y][var->x];
	  var->j = var->j + 1;
	  var->y = var->y - 1;
	}
      var->tmp[var->i][var->j] = '\0';
      var->i = var->i + 1;
      var->x = var->x + 1;
    }
  if (turn_check(ctx) == 0)
    return (turn_change_param(var, ctx));
  else
    return (-1);
}
