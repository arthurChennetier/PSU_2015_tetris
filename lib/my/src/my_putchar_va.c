/*
** my_putchar.c for my_putchar.c in /home/chauvi_d/rendu/day07/lib/my
** 
** Made by Chauvin Antoine
** Login   <chauvi_d@epitech.net>
** 
** Started on  Tue Oct  6 09:26:55 2015 Chauvin Antoine
** Last update Wed Jan 20 13:45:14 2016 Chauvin Antoine
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	my_putchar_va(va_list ap)
{
  char	c;

  c = va_arg(ap, int);
  write(1, &c, 1);
  return (0);
}
