/*
** my_put_uns_va.c for my_put_uns_va.c in /home/chauvi_d/rendu/my_printf/lib/my/src
** 
** Made by Chauvin Antoine
** Login   <chauvi_d@epitech.net>
** 
** Started on  Mon Nov  9 16:46:00 2015 Chauvin Antoine
** Last update Fri Mar 18 15:46:24 2016 Chauvin Antoine
*/

#include <stdarg.h>
#include "my.h"

int    my_put_uns_va(va_list ap)
{
  unsigned int   result;
  int   divisor;
  unsigned int	nb;

  nb = va_arg(ap, unsigned int);
  divisor = 1;
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
