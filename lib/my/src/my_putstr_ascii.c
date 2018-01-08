/*
** my_putstr_ascii.c for my_putstr_ascii.c in /home/chauvi_d/rendu/my_printf
** 
** Made by Chauvin Antoine
** Login   <chauvi_d@epitech.net>
** 
** Started on  Tue Nov 10 18:17:04 2015 Chauvin Antoine
** Last update Wed Jan 20 13:48:35 2016 Chauvin Antoine
*/

#include <stdarg.h>
#include "my.h"

void	convert_nb(char c)
{
  char base[9] = "01234567";
  int	nb;

  nb = c;
  my_putchar(92);
  if (nb < 7)
    my_putchar ('0');
  if (nb < 63)
    my_putchar('0');
  my_put_nbrbase(nb, base);
}

int	my_putstr_ascii(va_list c)
{
  int nb_carac;
  char	*str;

  str = va_arg(c, char*);
  nb_carac = 0;
  while (str[nb_carac] != '\0')
    {
      if (str[nb_carac] < 33 || str[nb_carac] == 127)
	  convert_nb(str[nb_carac]);
      else
	my_putchar(str[nb_carac]);
      nb_carac = nb_carac + 1;
    }
  return (0);
}
