/*
** check_err.c for tetris in /home/chenne_a/rendu/semestre2/PSU_2016/test/PSU_2015_tetris/game
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Sun Mar 20 18:37:49 2016 Arthur Chennetier
** Last update Sun Mar 20 18:39:46 2016 Arthur Chennetier
*/

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <curses.h>
#include "map.h"
#include "my.h"

int		check_err(int err, t_game *ctx, int indic)
{
  if (ctx->indic > 20000 - (1000 * ctx->var->level))
    {
      if ((err = move_piece(ctx)) == -1)
	indic = 0;
      if (err == -2)
	return (-1);
    }
  return (indic);
}
