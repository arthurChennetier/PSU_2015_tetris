/*
** free_2d.c for free_2d in /home/chauvi_d/rendu/Systunix/PSU_2015_minishell1/lib/my/src
** 
** Made by Chauvin Antoine
** Login   <chauvi_d@epitech.net>
** 
** Started on  Thu Jan 21 16:25:03 2016 Chauvin Antoine
** Last update Sun Jan 24 21:48:21 2016 Chauvin Antoine
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void	free_2d(char **str)
{
  int	i;

  if (str != NULL)
    {
      i = 0;
      while (str[i])
	{
	  if (str[i] != NULL)
	    free(str[i]);
	  i = i + 1;
	}
      free(str);
      str = NULL;
    }
}

