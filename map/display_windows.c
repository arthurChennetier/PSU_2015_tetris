/*
** display_windows.c for tetris in /home/chenne_a/rendu/semestre2/PSU_2016/PSU_2015_tetris/map
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Thu Feb 25 15:32:25 2016 Arthur Chennetier
** Last update Tue Mar 15 12:49:02 2016 Arthur Chennetier
*/

#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
#include "map.h"
#include "my.h"

void		display_score(WINDOW *score, t_score *var)
{
  wattron(score, COLOR_PAIR(1));
  mvwprintw(score, 0, 0, "/---------------------\\");
  mvwprintw(score, 1, 0, "|                     |");
  mvwprintw(score, 2, 0, "| High Score          |");
  mvwprintw(score, 2, 17, "%i", var->high_score);
  mvwprintw(score, 3, 0, "| Score               |");
  mvwprintw(score, 3, 17, "%i", var->actual_score);
  mvwprintw(score, 4, 0, "|                     |");
  mvwprintw(score, 5, 0, "| Lines               |");
  mvwprintw(score, 5, 18, "%i", var->line);
  mvwprintw(score, 6, 0, "| Level               |");
  mvwprintw(score, 6, 18, "%i", var->level);
  mvwprintw(score, 7, 0, "|                     |");
  mvwprintw(score, 8, 0, "| Timer:              |");
  display_time(score, var);
  mvwprintw(score, 9, 0, "|                     |");
  mvwprintw(score, 10, 0, "\\---------------------/");
  display_space_score(score, var);
  wattroff(score, COLOR_PAIR(1));
  touchwin(score);
  wrefresh(score);
}

void		display_game2(WINDOW *game, t_score *var)
{
  int		space;

  space = 1;
  mvwprintw(game, 0, 0, " ");
  mvwprintw(game, var->height - 1, 0, " ");
  while (space < var->width - 1)
    {
      mvwprintw(game, 0, space, "-");
      mvwprintw(game, var->height - 1, space, "-");
      space = space + 1;
    }
  space = 1;
  while (space < var->height - 1)
    {
      mvwprintw(game, space, var->width - 2, "|");
      space = space + 1;
    }
}

void		display_game(WINDOW *game, t_score *var)
{
  int		i;

  i = 1;
  wattron(game, COLOR_PAIR(1));
  while (i < var->height - 1)
    {
      mvwprintw(game, i, 0, " |");
      i = i + 1;
    }
  display_game2(game, var);
  wattroff(game, COLOR_PAIR(1));
}

void		display_next(WINDOW *next, t_score *var)
{
  int           i;

  i = 1;
  wattron(next, COLOR_PAIR(1));
  mvwprintw(next, 0, 0, "/Next--\\  ");
  mvwprintw(next, 1, 0, "|      |  ");
  mvwprintw(next, 2, 0, "|      |  ");
  mvwprintw(next, 3, 0, "|      |  ");
  mvwprintw(next, 4, 0, "|      |  ");
  mvwprintw(next, 5, 0, "\\------/  ");
  wattron(next, COLOR_PAIR(var->next.color));
  while (i <= var->next.height)
    {
      mvwprintw(next, i, 5 - var->next.width, var->next.piece[i - 1]);
      i = i + 1;
    }
  i = 6;
  wattron(next, COLOR_PAIR(2));
  while (i < var->height)
    {
      mvwprintw(next, i, 0, "          ");
      i = i + 1;
    }
  touchwin(next);
  wrefresh(next);
}

void		display_S(WINDOW *title)
{
  wattron(title, COLOR_PAIR(1));
  mvwprintw(title, 0, 20, "___");
  mvwprintw(title, 1, 20, "|  ");
  mvwprintw(title, 2, 20, "|__");
  mvwprintw(title, 3, 20, "  |");
  mvwprintw(title, 4, 20, "__|");
  wattroff(title, COLOR_PAIR(1));
}
