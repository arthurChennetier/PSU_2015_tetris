/*
** test_tetrimino.c for tetris in /home/chenne_a/rendu/semestre2/PSU_2016/PSU_2015_tetris/map
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Mon Mar 14 17:13:15 2016 Arthur Chennetier
** Last update Mon Mar 14 17:42:26 2016 Arthur Chennetier
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

int		algo_dimensions(char *name, int i, t_tetris info)
{
  int		ymax;
  int		y;
  int		j;

  y = 0;
  ymax = 0;
  j = 0;
  while (name[i] != '\0')
    {
      while (name[i] != '\n' && name[i] != '\0')
        {
          if (name[i] != '*' && name[i] != ' ')
            return (-1);
          i = i + 1;
          y = y + 1;
        }
      if (ymax <= y)
        ymax = y;
      y = 0;
      i = i + 1;
      j = j + 1;
    }
  if (ymax != info.width || j != info.height)
    return (-1);
  return (0);
}

int		test_dimensions(t_tetris info, char *name)
{
  int		i;
  int		tmp;

  i = 0;
  while (name[i] != '\n' && name[i] != '\0')
    i = i + 1;
  if (name[i] == '\0')
    return (-1);
  i = i + 1;
  tmp = i;
  if (algo_dimensions(name, i, info) == -1)
    return (-1);
  return (tmp);
}

int		width_init(char *name)
{
  int		i;
  int		nbr;
  int		divide;

  divide = 1;
  nbr = 0;
  i = 0;
  while (name[i] != ' ' && name[i] != '\0')
    {
      divide = divide * 10;
      i = i + 1;
    }
  i = 0;
  while (divide > 9)
    {
      divide = divide / 10;
      if (name[i] < '1' || name[i] > '9')
        return (0);
      nbr = nbr + divide * (name[i] - 48);
      i = i + 1;
    }
  return (nbr);
}

int		height_init(char *name)
{
  t_test	test;

  test.divide = 1;
  test.nbr = 0;
  test.i = 0;
  while (name[test.i] != ' ' && name[test.i] != '\0')
    test.i = test.i + 1;
  test.i = test.i + 1;
  test.tmp = test.i;
  while (name[test.i] != ' ' && name[test.i] != '\0')
    {
      test.divide = test.divide * 10;
      test.i = test.i + 1;
    }
  test.i = test.tmp;
  while (test.divide > 9)
    {
      test.divide = test.divide / 10;
      if (name[test.i] < '1' || name[test.i] > '9')
        return (0);
      test.nbr = test.nbr + test.divide * (name[test.i] - 48);
      test.i = test.i + 1;
    }
  return (test.nbr);
}

int		color_init(char *name)
{
  int           i;
  int           nbr;
  int           divide;
  int           tmp;

  divide = 1;
  nbr = 0;
  if ((i = begin_color(name)) == -1)
    return (0);
  tmp = i;
  while (name[i] != '\n' && name[i] != '\0')
    {
      divide = divide * 10;
      i = i + 1;
    }
  i = tmp;
  while (divide > 9)
    {
      divide = divide / 10;
      if (name[i] < '1' || name[i] > '9')
        return (0);
      nbr = nbr + divide * (name[i] - 48);
      i = i + 1;
    }
  return (nbr);
}
