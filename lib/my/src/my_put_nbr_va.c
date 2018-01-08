/*
** my_put_nbr.c for my_put_nbr.c in /home/chauvi_d/rendu/day03
** 
** Made by Chauvin Antoine
** Login   <chauvi_d@epitech.net>
** 
** Started on  Thu Oct  1 16:13:17 2015 Chauvin Antoine
** Last update Wed Jan 20 13:46:22 2016 Chauvin Antoine
*/

#include <stdarg.h>
#include "my.h"

int    my_put_nbr_va(va_list ap)
{
  int   result;
  int   divisor;
  int	nb;

  nb = va_arg(ap, int);
  divisor = 1;
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  while ((nb / divisor) >= 10)
    divisor = divisor * 10;
  while (divisor > 0)
    {
      result = (nb / divisor) % 10;
      my_putchar(48 + result);
     divisor = divisor / 10;
    }
  return (0);
}
