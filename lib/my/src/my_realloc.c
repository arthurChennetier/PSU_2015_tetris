/*
** my_realloc.c for my_realloc.c in /home/chauvi_d/rendu/Systunix/PSU_2015_minishell1/lib/my/src
** 
** Made by Chauvin Antoine
** Login   <chauvi_d@epitech.net>
** 
** Started on  Tue Jan 19 14:47:18 2016 Chauvin Antoine
** Last update Sun Jan 24 21:51:34 2016 Chauvin Antoine
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char    *my_realloc(char *str, int size)
{
  char  *tmp;
  int   i;

  if (size == 0)
    {
      if (str != NULL)
        free(str);
      return (NULL);
    }
  i = 0;
  tmp = malloc(sizeof(char) * (size + 1));
  if (tmp == NULL)
    return (NULL);
  while (str[i] && i < size)
    {
      tmp[i] = str[i];
      i = i + 1;
    }
  if (str != NULL)
    free(str);
  tmp[i] = 0;
  return (tmp);
}
