/*
** my_get_nbr.c for my_get_nbr.c in /home/chauvi_d/lib/my/src
** 
** Made by Chauvin Antoine
** Login   <chauvi_d@epitech.net>
** 
** Started on  Fri Oct  9 18:35:03 2015 Chauvin Antoine
** Last update Thu Feb 25 15:29:51 2016 chauvi_d
*/

#include "my.h"

int	my_mult(char *str, int mult)
{
  int	count;

  mult = 1;
  count = 0;
  while (str[count])
    {
      if (str[count] >= '0' && str[count] <= '9')
	mult = mult * 10;
      count = count + 1;
    }
  mult = mult / 10;
  return (mult);
}

int     my_getnbr(char *str)
{
  int   result;
  int   mult;
  int   count;
  int   calc;
  int	sign;

  sign = 1;
  result = 0;
  count = 0;
  mult = my_mult(str, 0);
  while (str[count])
    {
      if (str[count] == '-')
	sign = sign * (-1);
      if (str[count] >= '0' && str[count] <= '9')
        {
          calc = ((str[count] - 48) * mult);
          result = result + calc;
          mult = mult / 10;
        }
      count = count + 1;
    }
  result = result * sign;
  return (result);
}
