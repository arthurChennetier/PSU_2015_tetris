/*
** game.c for tetris in /home/chenne_a/rendu/semestre2/PSU_2016/PSU_2015_tetris/game
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Wed Mar  9 11:47:27 2016 Arthur Chennetier
** Last update Sun Mar 20 18:40:35 2016 Arthur Chennetier
*/

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <curses.h>
#include "map.h"
#include "my.h"

int		del_line(t_game *ctx, int i, int j)
{
  j = i + j;
  while (i != j)
    {
      ctx->game[i] = ' ';
      i++;
    }
  return (0);
}

int		check_plat(t_game *ctx)
{
  int		i;
  int		j;
  int		nb_c;

  i = 0;
  while (ctx->game[i])
    {
      j = 0;
      nb_c = 0;
      while (j != ctx->keys->col)
        {
          if (ctx->game[i + j] == '*')
            nb_c++;
          j++;
        }
      if (nb_c == ctx->keys->col)
        {
          del_line(ctx, i, j);
	  ctx->var->line = ctx->var->line + 1;
	  ctx->var->actual_score = ctx->var->actual_score + 100;
	  move_down_plat(ctx, i, j);
        }
      i = i + ctx->keys->col;
    }
  return (0);
}

int			display_plat(WINDOW *game, char *plat,
				     t_key *keys, int *color)
{
  int			i;
  int			x;
  int			y;

  i = 0;
  y = 1;
  while (y < keys->row + 1)
    {
      x = 2;
      while (x < keys->col + 2)
	{
	  if (color[i] != -1)
	    wattron(game, COLOR_PAIR(color[i]));
	  mvwaddch(game, y, x, plat[i]);
	  i = i + 1;
	  x = x + 1;
	}
      y = y + 1;
    }
  touchwin(game);
  wrefresh(game);
  return (0);
}

int			move_piece(t_game *ctx)
{
  ctx->indic = 0;
  if (clear_tetri(ctx) == -1)
    return (-1);
  if (check_tetri(ctx, ctx->idx + ctx->keys->col) != -1)
    ctx->idx = ctx->idx + ctx->keys->col;
  else if (ctx->idx >= 0 && ctx->idx <= ctx->keys->col)
    return (-2);
  else
    return (delay_passed(ctx));
  if (add_tetri(ctx) == -1)
    return (-1);
  return (0);
}

int			game(t_game *ctx)
{
  static int	indic = 0;
  int		err;

  err = 0;
  if (indic == 0)
    {
      check_plat(ctx);
      ctx->var->tetrimino = ctx->var->next;
      ctx->var->next = ctx->piece[rand() % ctx->size];
      while (ctx->var->next.height == 0 || ctx->var->next.width == 0
	    || ctx->var->next.color == 0 || ctx->var->next.piece == NULL)
	ctx->var->next = ctx->piece[rand() % ctx->size];
      ctx->idx = ctx->var->width / 2 - ctx->var->tetrimino.width / 2;
      add_tetri(ctx);
      indic = 1;
    }
  if (ctx->keys->without == 1)
    display_next(ctx->all->next, ctx->var);
  display_plat(ctx->all->game, ctx->game, ctx->keys, ctx->color);
  if ((indic = check_err(err, ctx, indic)) == -1)
    return (-1);
  if (user_key(ctx) == -1)
    return (-1);
  return (0);
}
