/*
** my_put_base.c for my_put_base.c in /home/chauvi_d/rendu/my_printf
** 
** Made by Chauvin Antoine
** Login   <chauvi_d@epitech.net>
** 
** Started on  Tue Nov 10 15:54:16 2015 Chauvin Antoine
** Last update Fri Mar 18 15:49:00 2016 Chauvin Antoine
*/

#include "my.h"

int	my_put_oct(va_list c)
{
  unsigned int	nb;

  nb = va_arg(c, unsigned int);
  my_put_unsbase(nb, "01234567");
  return (0);
}

int	my_put_hex(va_list c)
{
  unsigned int	nb;

  nb = va_arg(c, unsigned int);
  my_put_unsbase(nb, "0123456789abcdef");
  return (0);
}

int	my_put_hexup(va_list c)
{
  unsigned int	nb;

  nb = va_arg(c, unsigned int);
  my_put_unsbase(nb, "0123456789ABCDEF");
  return (0);
}

int	my_put_bin(va_list c)
{
  unsigned int	nb;

  nb = va_arg(c, unsigned int);
  my_put_unsbase(nb, "01");
  return (0);
}

