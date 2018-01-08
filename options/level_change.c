/*
** level_change.c for tetris in /home/chenne_a/rendu/semestre2/PSU_2016/PSU_2015_tetris/options
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Thu Mar 17 17:12:11 2016 Arthur Chennetier
** Last update Thu Mar 17 17:28:28 2016 Arthur Chennetier
*/

#include <unistd.h>
#include "my.h"
#include "map.h"

int		change_level2(int level, char *arg, t_key *keys, int n)
{
  level = my_getnbr(arg);
  if (level == 0 || level > 20)
    {
      my_printf("Wrong level (max 20)\n");
      return (-1);
    }
  keys->level = level;
  return (n);
}

int		change_map_free(char *row, char *col, int n)
{
  if (row != NULL && col != NULL)
    {
      free(row);
      free(col);
    }
  return (n);
}
