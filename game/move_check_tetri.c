/*
** move_check_tetri.c for tetris in /home/chenne_a/rendu/semestre2/PSU_2016/PSU_2015_tetris/game
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Mon Mar 14 17:48:09 2016 Arthur Chennetier
** Last update Thu Mar 17 16:51:47 2016 Arthur Chennetier
*/

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <curses.h>
#include "map.h"
#include "my.h"

int		only_space_down(t_game *ctx, t_move var)
{
  int		i;

  i = var.y;
  while (ctx->var->tetrimino.piece[i] != NULL)
    {
      if (ctx->var->tetrimino.piece[i][var.x] != ' ')
	return (-1);
      i = i + 1;
    }
  return (0);
}

int		clear_tetri(t_game *ctx)
{
  t_move	var;

  var.tmp = ctx->idx;
  if (ctx->idx + ctx->var->tetrimino.height * ctx->keys->col
      >= ctx->keys->row * ctx->keys->col)
    return (-1);
  var.pos = var.tmp;
  var.y = 0;
  while (ctx->var->tetrimino.piece[var.y] != NULL)
    {
      var.x = 0;
      while (ctx->var->tetrimino.piece[var.y][var.x] != '\0')
        {
	  if (only_space_down(ctx, var) == -1 || ctx->game[var.pos] == ' ' ||
	      (ctx->game[var.pos] == ' ' &&
	       ctx->var->tetrimino.piece[var.y][var.x] == ' '))
	    clear_case(ctx, var);
          var.pos = var.pos + 1;
          var.x = var.x + 1;
        }
      var.y = var.y + 1;
      var.pos = var.tmp + ctx->keys->col;
      var.tmp = var.pos;
    }
  return (0);
}

int		check_tetri(t_game *ctx, int idx)
{
  t_move	var;

  var.tmp = idx;
  var.pos = var.tmp;
  var.y = 0;
  while (ctx->var->tetrimino.piece[var.y] != NULL)
    {
      var.x = 0;
      while (ctx->var->tetrimino.piece[var.y][var.x] != '\0')
        {
          if (ctx->game[var.pos] != ' ' &&
	      ctx->var->tetrimino.piece[var.y][var.x] != ' ')
            return (-1);
          var.pos = var.pos + 1;
          var.x = var.x + 1;
        }
      var.y = var.y + 1;
      var.pos = var.tmp + ctx->keys->col;
      var.tmp = var.pos;
    }
  return (0);
}

t_move			algo_add(t_game *ctx, t_move var)
{
  if (ctx->color[var.pos] != -1 &&
      ctx->var->tetrimino.piece[var.y][var.x] == ' '
      && ctx->game[var.pos] == '*')
    {
      var.pos = var.pos + 1;
      var.x = var.x + 1;
    }
  else
    {
      ctx->game[var.pos] = ctx->var->tetrimino.piece[var.y][var.x];
      ctx->color[var.pos] = ctx->var->tetrimino.color;
      var.pos = var.pos + 1;
      var.x = var.x + 1;
    }
  return (var);
}

int                     add_tetri(t_game *ctx)
{
  t_move		var;

  var.tmp = ctx->idx;
  var.pos = var.tmp;
  var.y = 0;
  while (ctx->var->tetrimino.piece[var.y] != NULL)
    {
      var.x = 0;
      while (ctx->var->tetrimino.piece[var.y][var.x] != '\0')
        {
          if (ctx->game[var.pos] == '*'
	      && ctx->var->tetrimino.piece[var.y][var.x] == '*')
            return (-1);
	  else
	    var = algo_add(ctx, var);
        }
      var.y = var.y + 1;
      var.pos = var.tmp + ctx->keys->col;
      var.tmp = var.pos;
    }
  return (0);
}
