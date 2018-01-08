/*
** fct_tetriminos.c for tetris in /home/chenne_a/rendu/semestre2
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Mon Mar  7 16:43:24 2016 Arthur Chennetier
** Last update Wed Mar  9 13:43:40 2016 chauvi_d
*/

#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "my.h"

int			*init_panel(int size)
{
  int			*panel;
  int			i;

  if ((panel = malloc(sizeof(int) * size)) == NULL)
    return (NULL);
  i = 0;
  while (i < size)
    {
      panel[i] = i + 1;
      i = i + 1;
    }
  return (panel);
}

int			my_tri_strcmp(char *str1, char *str2)
{
  int			i;

  i = 0;
  if (str1 == NULL || str2 == NULL)
    return (0);
  while (str1[i] != '\0' && str2[i] != '\0')
    {
      if (str1[i] != str2[i])
	return (str1[i] - str2[i]);
      i = i + 1;
    }
  return (my_strlen(str1) - my_strlen(str2));
}

void			tri_algo(t_tri *tri, t_tetris *piece, int size)
{
  while (tri->y < size)
    {
      while (tri->i < size)
	{
	  if (tri->panel[tri->i] != 0)
	    {
	      tri->dif = my_tri_strcmp(piece[tri->tmp].name,
				       piece[tri->i].name);
	      if (tri->dif > 0)
		tri->tmp = tri->i;
	    }
	  tri->i = tri->i + 1;
	}
      tri->i = 1;
      tri->order[tri->y] = tri->tmp;
      tri->panel[tri->tmp] = 0;
      tri->tmp = tri->tmp + 1;
      if ((tri->tmp >= size || tri->panel[tri->tmp] == 0) && tri->y + 1 < size)
	{
	  tri->tmp = 0;
	  while (tri->panel[tri->tmp] == 0)
	    tri->tmp = tri->tmp + 1;
	}
      tri->y = tri->y + 1;
    }
}

int			*my_tri(t_tetris *piece, int size)
{
  t_tri			*tri;

  if ((tri = malloc(sizeof(t_tri))) == NULL)
    return (NULL);
  if ((tri->order = malloc(sizeof(int) * size)) == NULL)
    return (NULL);
  if ((tri->panel = init_panel(size)) == NULL)
    return (NULL);
  tri->tmp = 0;
  tri->y = 0;
  tri->i = 1;
  tri_algo(tri, piece, size);
  return (tri->order);
}

int			tetriminos_option()
{
  t_tetris		*piece;
  int			*order;
  int			size;

  size = 0;
  if ((piece = init_tetrimino()) == NULL)
    return (-1);
  while (piece[size].name != NULL)
    size = size + 1;
  if ((order = my_tri(piece, size)) == NULL)
    return (-1);
  print_tetriminos(piece, order, size);
  return (0);
}
