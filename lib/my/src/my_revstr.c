/*
** my_revstr.c for RETURN in /home/chauvi_d/rendu/day06
** 
** Made by Chauvin Antoine
** Login   <chauvi_d@epitech.net>
** 
** Started on  Mon Oct  5 11:01:09 2015 Chauvin Antoine
** Last update Wed Feb 10 14:36:34 2016 Chauvin Antoine
*/

#include <unistd.h>
#include "my.h"

char	*my_revstr(char *str)
{
  char	*rev;
  int	i;
  int	n;

  n = 0;
  i = 0;
  while (str[i])
    i++;
  rev = malloc(sizeof(char) * my_strlen(str) + 1);
  if (rev == NULL)
    return (NULL);
  while (i)
    {
      rev[n] = str[i - 1];
      i = i - 1;
      n++;
    }
  rev[n] = 0;
  return (rev);
}
