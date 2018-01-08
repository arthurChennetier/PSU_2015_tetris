/*
** time.c for tetris in /home/chenne_a/rendu/semestre2/PSU_2016/PSU_2015_tetris/map
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Thu Mar 17 16:34:58 2016 Arthur Chennetier
** Last update Thu Mar 17 16:35:00 2016 Arthur Chennetier
*/

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <curses.h>
#include "map.h"
#include "my.h"

void			color_ini()
{
  start_color();
  init_pair(1, COLOR_BLACK, COLOR_WHITE);
  init_pair(2, COLOR_RED, COLOR_WHITE);
  init_pair(3, COLOR_GREEN, COLOR_WHITE);
  init_pair(4, COLOR_YELLOW, COLOR_WHITE);
  init_pair(5, COLOR_BLUE, COLOR_WHITE);
  init_pair(6, COLOR_MAGENTA, COLOR_WHITE);
  init_pair(7, COLOR_CYAN, COLOR_WHITE);
}

void			refresh_time(t_score *var)
{
  time_t		a;

  a = time(&a);
  if ((var->seconds = (int)a - (int)var->time + var->seconds) >= 60)
    {
      var->minutes = var->minutes + 1;
      var->seconds = var->seconds % 60;
    }
  var->time = a;
}

void			display_time(WINDOW *score, t_score *var)
{
  if (var->minutes < 10 && var->seconds < 10)
    {
      mvwprintw(score, 8, 16, "0");
      mvwprintw(score, 8, 17, "%i:", var->minutes);
      mvwprintw(score, 8, 19, "0");
      mvwprintw(score, 8, 20, "%i", var->seconds);
    }
  else if (var->seconds < 10 && var->minutes >= 10)
    {
      mvwprintw(score, 8, 16, "%i:", var->minutes);
      mvwprintw(score, 8, 19, "0");
      mvwprintw(score, 8, 20, "%i", var->seconds);
    }
  else if (var->seconds >= 10 && var->minutes < 10)
    {
      mvwprintw(score, 8, 16, "0", var->minutes);
      mvwprintw(score, 8, 17, "%i:", var->minutes);
      mvwprintw(score, 8, 19, "%i", var->seconds);
    }
  else
    mvwprintw(score, 8, 16, "%i:%i", var->minutes, var->seconds);
}

void			my_bzero(char *str, int size)
{
  int			i;

  i = 0;
  while (i < size)
    {
      str[i] = '\0';
      i = i + 1;
    }
}
