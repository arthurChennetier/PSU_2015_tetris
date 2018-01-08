/*
** my_put_nbrbase.c for my_put_nbrbase.c in /home/chauvi_d/rendu/my_printf
** 
** Made by Chauvin Antoine
** Login   <chauvi_d@epitech.net>
** 
** Started on  Tue Nov 10 14:18:42 2015 Chauvin Antoine
** Last update Tue Nov 10 16:29:57 2015 Chauvin Antoine
*/

#include "my.h"

int    my_put_nbrbase(int nb, char *base)
{
  int   result;
  int   divisor;

  divisor = 1;
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  while ((nb / divisor) >= my_strlen(base))
    divisor = divisor * my_strlen(base);
  while (divisor > 0)
    {
      result = (nb / divisor) % my_strlen(base);
      if (result < 0 || result > 9)
	my_putchar(base[result]);
      else
	my_putchar(48 + result);
      divisor = divisor / my_strlen(base);
    }
  return (0);
}
