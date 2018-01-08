/*
** my_printf.c for my_printf.c in /home/chauvi_d/rendu/my_printf
** 
** Made by Chauvin Antoine
** Login   <chauvi_d@epitech.net>
** 
** Started on  Mon Nov  2 15:47:19 2015 Chauvin Antoine
** Last update Fri Mar 18 15:42:10 2016 Chauvin Antoine
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

t_fonction	fonction_tab[] =
  {
    {'c', &my_putchar_va},
    {'i', &my_put_nbr_va},
    {'d', &my_put_nbr_va},
    {'s', &my_putstr_va},
    {'u', &my_put_uns_va},
    {'o', &my_put_oct},
    {'x', &my_put_hex},
    {'X', &my_put_hexup},
    {'b', &my_put_bin},
    {'S', &my_putstr_ascii},
    {'p', &my_put_adress},
    {'%', &my_putchar_pourcent},
    {0, NULL}
  };

int	put_arg(char flag, va_list ap)
{
  int	n;

  n = 0;
  while (fonction_tab[n].flag != flag && n != 12)
      n = n + 1;
  if (n == 12 && flag >= '0' && flag <= '9')
    {
      my_putchar('%');
      my_putchar(flag);
      return (0);
    }
  else if (n == 12 && flag >= 'a' && flag <= 'z')
    {
      my_putchar('%');
      my_putchar(flag);
      return (0);
    }
  else if (n == 12)
    return (0);
  return (fonction_tab[n].ptr(ap));
}

int	my_printf(const char *format, ...)
{
  va_list ap;
  int	count;

  count = 0;
  va_start(ap, format);
  if (format == NULL)
    {
      my_putstr(ERROR_MSG);
      exit(2);
    }
  while (format[count])
    {
      if (format[count] == '%')
	{
	  put_arg(format[count + 1], ap);
	  count = count + 1;
	}
      else
	my_putchar(format[count]);
      count = count + 1;
    }
  va_end(ap);
  return (0);
}
