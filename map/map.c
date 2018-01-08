/*
** map.c for tetris in /home/chenne_a/rendu/semestre2/PSU_2016/PSU_2015_tetris/map
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Thu Mar 17 16:34:43 2016 Arthur Chennetier
** Last update Sun Mar 20 18:45:20 2016 Arthur Chennetier
*/

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <curses.h>
#include "map.h"
#include "my.h"

char		*my_path(char *name)
{
  char		*new;
  int		i;
  int		y;

  y = 0;
  i = 13;
  if ((new = malloc(sizeof(char) * (my_strlen(name) + i + 1))) == NULL)
    return (NULL);
  new = my_strcpy(new, "./tetriminos/");
  while (name[y] != '\0')
    {
      new[i] = name[y];
      i = i + 1;
      y = y + 1;
    }
  new[i] = '\0';
  return (new);
}

int			init_var(t_score *var, t_key *keys,
				 t_tetris *piece, int size)
{
  time_t		a;

  var->height = keys->row + 2;
  var->width = keys->col + 4;
  var->high_score = get_high_score();
  var->actual_score = 0;
  var->line = 0;
  while (var->next.height == 0 || var->next.width == 0
	 || var->next.color == 0 || var->next.piece == NULL)
    var->next = piece[rand() % size];
  var->level = keys->level;
  var->time = time(&a);
  var->minutes = 0;
  var->seconds = 0;
  curs_set(false);
  color_ini();
  noecho();
  if (var->height > LINES || var->width + 23 + 11 > COLS ||
      var->height < 20 || var->width < 10)
    return (-1);
  return (0);
}

t_game		*init_game_tab(t_score *var, t_window *all,
			       t_key *keys, t_tetris *piece)
{
  t_game	*ctx;

  if ((ctx = malloc(sizeof(t_game))) == NULL)
    return (NULL);
  if (ctx == NULL)
    return (NULL);
  ctx->size = 0;
  ctx->indic = 0;
  while (piece[ctx->size].name != NULL )
    ctx->size = ctx->size + 1;
  ctx->keys = keys;
  ctx->piece = piece;
  ctx->var = var;
  srand(time(NULL));
  while (ctx->var->next.height == 0 || ctx->var->next.width == 0
	 || ctx->var->next.color == 0 || ctx->var->next.piece == NULL)
    ctx->var->next = ctx->piece[rand() % ctx->size];
  ctx->var->tetrimino = var->next;
  ctx->idx = ctx->var->width / 2 - ctx->var->tetrimino.width / 2;
  ctx->all = all;
  if ((ctx->game = init_game(keys)) == NULL)
    return (NULL);
  if ((ctx->color = init_tab_color(keys)) == NULL)
    return (NULL);
  return (ctx);
}

int		refresh_game(t_score *var, t_window *all,
			     t_key *keys, t_tetris *piece)
{
  int		i;
  t_game	*ctx;

  mod(0);
  if ((buff = malloc(sizeof(char) * 12)) == NULL)
    return (-1);
  my_bzero(buff, 12);
  ctx = init_game_tab(var, all, keys, piece);
  while (my_strcmp(buff, keys->kq) != 0)
    {
      ctx->indic = ctx->indic + 1;
      if ((i = read(0, buff, 10)) == -1)
	return (-1);
      buff[i] = 0;
      refresh_time(var);
      if (ctx->var->actual_score >= ctx->var->level * 1000)
	ctx->var->level = ctx->var->level + 1;
      if (game(ctx) == -1)
	return (end_high_score(ctx));
      display_score(all->score, var);
    }
  write_high_score(ctx->var->actual_score);
  mod(1);
  return (0);
}

int			launch_tetris(t_key *keys)
{
  t_window		*all;
  WINDOW		*win;
  t_score		*var;
  t_tetris		*piece;
  int			size;

  size = 0;
  if ((all = malloc(sizeof(t_window))) == NULL ||
      (var = malloc(sizeof(t_score))) == NULL)
    return (-1);
  if ((win = initscr()) == NULL || (piece = init_tetrimino()) == NULL)
    return (-1);
  while (piece[size].name != NULL)
    size = size + 1;
  if (size == 0)
    return (-1);
  var->next = piece[rand() % size];
  if (init_var(var, keys, piece, size) == -1)
    return (-1);
  if (create_map(win, var, all, keys->without) == -1)
    return (-1);
  if (refresh_game(var, all, keys, piece) == -1)
    return (-1);
  endwin();
  return (0);
}
