/*
** init_game.c for tetris in /home/chenne_a/rendu/semestre2/PSU_2016/PSU_2015_tetris/game
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Mon Mar 14 17:45:08 2016 Arthur Chennetier
** Last update Mon Mar 14 17:46:38 2016 Arthur Chennetier
*/

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <curses.h>
#include "map.h"
#include "my.h"

int		*init_tab_color(t_key *keys)
{
  int		*color;
  int		i;
  int		size;

  i = 0;
  size = keys->row * keys->col + keys->row + 1;
  if ((color = malloc(sizeof(int) * size)) == NULL)
    return (NULL);
  while (i < size)
    {
      color[i] = -1;
      i = i + 1;
    }
  color[10] = 2;
  return (color);
}

char		*init_game(t_key *keys)
{
  char		*game;
  int		i;
  int		size;

  size = keys->row * keys->col + keys->row + 1;
  i = 0;
  if ((game = malloc(sizeof(char) * size)) == NULL)
    return (NULL);
  while (i < size - 1)
    {
      game[i] = ' ';
      i = i + 1;
    }
  game[i] = '\0';
  return (game);
}
