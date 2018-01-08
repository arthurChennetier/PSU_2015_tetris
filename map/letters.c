/*
** letters.c for tetris in /home/chenne_a/rendu/semestre2/PSU_2016/PSU_2015_tetris/map
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Wed Feb 24 17:54:24 2016 Arthur Chennetier
** Last update Mon Mar 14 13:46:26 2016 Arthur Chennetier
*/

#include <curses.h>
#include "map.h"

void		display_T(WINDOW *title)
{
  wattron(title, COLOR_PAIR(1));
  mvwprintw(title, 0, 0, "___ ");
  mvwprintw(title, 1, 0, " |  ");
  mvwprintw(title, 2, 0, " |  ");
  mvwprintw(title, 3, 0, " |  ");
  mvwprintw(title, 4, 0, " |  ");
  wattroff(title, COLOR_PAIR(1));
}

void		display_E(WINDOW *title)
{
  wattron(title, COLOR_PAIR(1));
  mvwprintw(title, 0, 4, "___ ");
  mvwprintw(title, 1, 4, "|   ");
  mvwprintw(title, 2, 4, "|__  ");
  mvwprintw(title, 3, 4, "|   ");
  mvwprintw(title, 4, 4, "|__ ");
  wattroff(title, COLOR_PAIR(1));
}

void		display_second_T(WINDOW *title)
{
  wattron(title, COLOR_PAIR(1));
  mvwprintw(title, 0, 8, "___ ");
  mvwprintw(title, 1, 8, " |  ");
  mvwprintw(title, 2, 8, " |  ");
  mvwprintw(title, 3, 8, " |  ");
  mvwprintw(title, 4, 8, " |  ");
  wattroff(title, COLOR_PAIR(1));
}

void		display_R(WINDOW *title)
{
  wattron(title, COLOR_PAIR(1));
  mvwprintw(title, 0, 12, "___ ");
  mvwprintw(title, 1, 12, "| | ");
  mvwprintw(title, 2, 12, "|_  ");
  mvwprintw(title, 3, 12, "| | ");
  mvwprintw(title, 4, 12, "| | ");
  wattroff(title, COLOR_PAIR(1));
}

void		display_I(WINDOW *title)
{
  wattron(title, COLOR_PAIR(1));
  mvwprintw(title, 0, 16, " #  ");
  mvwprintw(title, 1, 16, "    ");
  mvwprintw(title, 2, 16, " |  ");
  mvwprintw(title, 3, 16, " |  ");
  mvwprintw(title, 4, 16, " |  ");
  wattroff(title, COLOR_PAIR(1));
}
