/*
** my_put_unsbase.c for my_put_unsbase.c in /home/chauvi_d/rendu/my_printf/lib/my/src
** 
** Made by Chauvin Antoine
** Login   <chauvi_d@epitech.net>
** 
** Started on  Tue Nov 10 15:08:50 2015 Chauvin Antoine
** Last update Wed Jan 20 13:47:56 2016 Chauvin Antoine
*/

#include <stdio.h>
#include "my.h"

int    my_put_unsbase(unsigned int nb, char *base)
{
  unsigned int   result;
  unsigned int   divisor;

  divisor = 1;
  while ((nb / divisor) >= (unsigned int)my_strlen(base))
    divisor = divisor * my_strlen(base);
  while (divisor > 0)
    {
      result = (nb / divisor) % my_strlen(base);
      if (result > 9)
	my_putchar(base[result]);
      else
	my_putchar(48 + result);
      divisor = divisor / my_strlen(base);
    }
  return (0);
}
