/*
** my_putchar.c for my_putchar.c in /home/chauvi_d/rendu/day07/lib/my
** 
** Made by Chauvin Antoine
** Login   <chauvi_d@epitech.net>
** 
** Started on  Tue Oct  6 09:26:55 2015 Chauvin Antoine
** Last update Wed Jan 20 13:48:54 2016 Chauvin Antoine
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
