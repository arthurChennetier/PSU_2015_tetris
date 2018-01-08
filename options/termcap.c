/*
** termcap.c for tetris in /home/chauvi_d/Rendu-2015-Epitech/rendu/Systunix/PSU_2015_tetris/options
** 
** Made by chauvi_d
** Login   <chauvi_d@epitech.net>
** 
** Started on  Sat Mar  5 16:43:51 2016 chauvi_d
** Last update Thu Mar 17 17:34:44 2016 Arthur Chennetier
*/

#include <curses.h>
#include <term.h>
#include <stdio.h>
#include "my.h"
#include "map.h"

char    *my_getenv(char **env, char *str)
{
  int   i;
  int   n;
  char  *path;
  int   j;

  n = 0;
  j = 0;
  while (env[n])
    {
      i = 0;
      while (str[i] == env[n][i])
        i++;
      if (i == my_strlen(str) && env[n][i] == '=')
        {
          if ((path = malloc(sizeof(char) *
                             (my_strlen(env[n]) - i + 1))) == NULL)
            return (NULL);
          while (env[n][i++])
            path[j++] = env[n][i];
          return (path);
        }
      n++;
    }
  return (NULL);
}

char	*check_cap(char *key, char *cap)
{
  int	i;
  char	*s;

  i = 0;
  if (key == NULL)
    {
      if ((s = tigetstr(cap)) == (char*) -1 || s == NULL)
	{
	  my_printf("Error : missing capacity %s\n", cap);
	  return (NULL);
	}
      key = malloc(sizeof(char) * my_strlen(s) + 1);
      if (key == NULL)
	return (NULL);
      while (s[i])
	{
	  key[i] = s[i];
	  i++;
	}
      key[i] = 0;
    }
  return (key);
}

int	check_kp_kq(t_key *keys)
{
  if (keys->kq == NULL)
    {
      keys->kq = malloc(sizeof(char) * 2);
      if (keys->kq == NULL)
	return (-1);
      keys->kq[0] = 'q';
      keys->kq[1] = 0;
    }
  if (keys->kp == NULL)
    {
      keys->kp = malloc(sizeof(char) * 2);
      if (keys->kp == NULL)
	return (-1);
      keys->kp[0] = ' ';
      keys->kp[1] = 0;
    }
  return (0);
}

int	termcap(char **env, t_key *keys)
{
  char	*s;
  char	*term;
  int	err;
  int	i;

  env = env;
  term = NULL;
  i = setupterm(NULL, 1, &err);
  if (i != OK)
    {
      my_printf("Error : Wrong terminal (check $TERM)\n");
      return (-1);
    }
  if ((keys->kl = check_cap(keys->kl, "kcub1")) == NULL
      || (keys->kr = check_cap(keys->kr, "kcuf1")) == NULL
      || (keys->kd = check_cap(keys->kd, "kcud1")) == NULL
      || (keys->kt = check_cap(keys->kt, "kcuu1")) == NULL
      || check_kp_kq(keys) == -1)
    return (-1);
  s = tigetstr("smkx");
  if (s != 0)
    putp(s);
  if (term != NULL)
    free(term);
  return (0);
}
