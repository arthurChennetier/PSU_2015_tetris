/*
** second_test_tetrimino.c for tetris in /home/chenne_a/rendu/semestre2/PSU_2016/PSU_2015_tetris/map
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Mon Mar 14 17:25:40 2016 Arthur Chennetier
** Last update Sun Mar 20 18:47:16 2016 Arthur Chennetier
*/

#include <curses.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "my.h"
#include "map.h"

int		begin_color(char *name)
{
  int		i;

  i = 0;
  while (name[i] != ' ' && name[i] != '\0')
    i = i + 1;
  i = i + 1;
  while (name[i] != ' ' && name[i] != '\0')
    i = i + 1;
  if (name[i] == '\0')
    return (-1);
  i = i + 1;
  return (i);
}

t_tetris	error_piece(t_tetris info)
{
  info.width = 0;
  info.height = 0;
  info.color = 0;
  info.piece = NULL;
  info.name = NULL;
  return (info);
}

int		end_high_score(t_game *ctx)
{
  write_high_score(ctx->var->actual_score);
  return (0);
}
