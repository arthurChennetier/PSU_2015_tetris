/*
** my_putchar_%.c for my_putchar_%.c in /home/chauvi_d/rendu/my_printf/lib/my/src
** 
** Made by Chauvin Antoine
** Login   <chauvi_d@epitech.net>
** 
** Started on  Thu Nov 12 11:51:08 2015 Chauvin Antoine
** Last update Wed Jan 20 13:45:59 2016 Chauvin Antoine
*/

#include <stdarg.h>
#include "my.h"

int	my_putchar_pourcent(va_list ap)
{
  (void)ap;
  my_putchar('%');
  return (0);
}
