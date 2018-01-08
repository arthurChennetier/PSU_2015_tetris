/*
** my_strcmp.c for my_strcmp.c in /home/chauvi_d/rendu/Systunix/PSU_2015_minishell1/lib/my/src
** 
** Made by Chauvin Antoine
** Login   <chauvi_d@epitech.net>
** 
** Started on  Thu Jan 21 17:38:14 2016 Chauvin Antoine
** Last update Mon Feb 22 10:47:20 2016 chauvi_d
*/

#include <unistd.h>

int	my_strcmp(const char *str1, const char *str2)
{
  if (NULL == str1 || NULL == str2)
    return (0);
  while (*str1 && *str1 == *str2)
    {
      str1++;
      str2++;
    }
  return (*str2 - *str1);
}
