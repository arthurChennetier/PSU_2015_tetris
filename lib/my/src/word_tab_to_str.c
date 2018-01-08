/*
** word_tab_to_str.c for word_tab_to_str in /home/chauvi_d/rendu/Systunix/PSU_2015_minishell1/lib/my/src
** 
** Made by Chauvin Antoine
** Login   <chauvi_d@epitech.net>
** 
** Started on  Fri Jan 22 15:34:14 2016 Chauvin Antoine
** Last update Fri Jan 22 16:33:51 2016 Chauvin Antoine
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char	*get_nb_words(char **str)
{
  int	size;
  int	a;
  int	b;
  char	*arr;

  size = 0;
  a = 0;
  while (str[a])
    {
      b = 0;
      while (str[a][b])
	{
	  size++;
	  b++;
	}
      a++;
    }
  arr = malloc(sizeof(char) * (size + 2));
  if (arr == NULL)
    return (NULL);
  return (arr);
}

char	*word_tab_to_str(char **str)
{
  char	*arr;
  int	i;
  int	j;
  int	k;

  k = 1;
  i = 1;
  if ((arr = get_nb_words(str)) == NULL)
    return (NULL);
  arr[0] = '/';
  while (str[i])
    {
      j = 0;
      while (str[i][j])
	arr[k++] = str[i][j++];
      i++;
    }
  return (arr);
}
