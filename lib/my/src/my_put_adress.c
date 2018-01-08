/*
** my_put_adress.c for my_put_adress in /home/chauvi_d/rendu/my_printf
** 
** Made by Chauvin Antoine
** Login   <chauvi_d@epitech.net>
** 
** Started on  Wed Nov 11 17:19:44 2015 Chauvin Antoine
** Last update Wed Nov 11 17:54:24 2015 Chauvin Antoine
*/

#include <stdarg.h>
#include "my.h"

int	my_put_adress(va_list ap)
{
  int	adress;

  adress = va_arg(ap, int);
  my_putstr("0x");
  my_put_nbrbase(adress, "01234567");
  return (0);
}
