/*
** display_windows2.c for tetris in /home/chenne_a/rendu/semestre2/PSU_2016/PSU_2015_tetris/map
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Thu Mar  3 14:21:49 2016 Arthur Chennetier
** Last update Tue Mar 15 12:50:15 2016 Arthur Chennetier
*/

#include <unistd.h>
#include <curses.h>
#include "map.h"

void			display_space_score(WINDOW *score, t_score *var)
{
  int			i;

  i = 11;
  while (i < var->height)
    {
      mvwprintw(score, i, 0, "                       ");
      i = i + 1;
    }
}

void			display_title(WINDOW *title)
{
  display_T(title);
  display_E(title);
  display_second_T(title);
  display_R(title);
  display_I(title);
  display_S(title);
  wattron(title, COLOR_PAIR(1));
  mvwprintw(title, 5, 0, "                       ");
  mvwprintw(title, 6, 0, "                       ");
  wattroff(title, COLOR_PAIR(1));
  touchwin(title);
  wrefresh(title);
}

int			display_all(t_window *all, t_score *var, int without)
{
  display_title(all->title);
  display_score(all->score, var);
  display_game(all->game, var);
  if (without == 1)
    display_next(all->next, var);
  if ((touchwin(all->game)) == ERR)
    return (-1);
  if ((wrefresh(all->game)) == ERR)
    return (-1);
  return (0);
}

int			create_map(WINDOW *win, t_score *var,
				   t_window *all, int without)
{
  if ((all->title = subwin(win, 7, 23, 0, 1)) == NULL)
    return (-1);
  if ((all->score = subwin(win, var->height - 7, 23, 7, 1)) == NULL)
    return (-1);
  if ((all->game = subwin(win, var->height, var->width, 0, 24)) == NULL)
    return (-1);
  if (without == 1 || without == 0)
    if ((all->next = subwin(win, var->height, 11, 0, var->width + 23)) == NULL)
      return (-1);
  if ((display_all(all, var, without)) == -1)
    return (-1);
  return (0);
}

void			refresh_map(t_window *all, t_score *var)
{
  clear();
  display_all(all, var, 1);
}
