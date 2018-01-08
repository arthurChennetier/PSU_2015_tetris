/*
** move_piece_right.c for tetris in /home/chenne_a/rendu/semestre2/PSU_2016/PSU_2015_tetris/game
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Thu Mar 17 16:39:10 2016 Arthur Chennetier
** Last update Thu Mar 17 16:48:06 2016 Arthur Chennetier
*/

#include "map.h"

int		delay_passed(t_game *ctx)
{
  add_tetri(ctx);
  return (-1);
}

void		clear_case(t_game *ctx, t_move var)
{
  ctx->color[var.pos] = -1;
  ctx->game[var.pos] = ' ';
}
