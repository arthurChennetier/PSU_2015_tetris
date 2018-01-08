/*
** my_putstr.c for my_putstr.c in /home/chauvi_d/rendu/day04
** 
** Made by Chauvin Antoine
** Login   <chauvi_d@epitech.net>
** 
** Started on  Thu Oct  1 13:29:25 2015 Chauvin Antoine
** Last update Mon Mar  7 11:44:30 2016 chauvi_d
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int	my_putstr_va(va_list ap)
{
  int nb_carac;
  char	*str;

  str = va_arg(ap, char*);
  if (str == NULL)
    return (0);
  nb_carac = 0;
  while (str[nb_carac] != '\0')
    {
      if (str[nb_carac] == 27)
	my_putstr("^E");
      else if (str[nb_carac] == ' ')
	my_putstr("(space)");
      else
	my_putchar(str[nb_carac]);
      nb_carac = nb_carac + 1;
    }
  return (0);
}
