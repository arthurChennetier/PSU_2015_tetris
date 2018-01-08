/*
** options.c for tetris in /home/chauvi_d/Rendu-2015-Epitech/rendu/Systunix/PSU_2015_tetris/options
** 
** Made by chauvi_d
** Login   <chauvi_d@epitech.net>
** 
** Started on  Wed Feb 24 17:41:35 2016 chauvi_d
** Last update Thu Mar 17 17:33:09 2016 Arthur Chennetier
*/

#include <unistd.h>
#include "map.h"
#include "my.h"

t_fct_key	fct_key[] =
  {
    {"--help", NULL, &print_help},
    {"-l", "--level=", &change_level},
    {"-kl", "--key-left=", &change_left},
    {"-kr", "--key-right=", &change_right},
    {"-kt", "--key-turn=", &change_turn},
    {"-kd", "--key-drop=", &change_drop},
    {"-kq", "--key-quit=", &change_quit},
    {"-kp", "--key-pause=", &change_pause},
    {"--map-size=", NULL, &change_map},
    {"-w", "--without-next", &change_w},
    {"-d", "--debug", &debug_on},
    {NULL, NULL, NULL}
  };

char	*get_check_for_double(char **av, int n)
{
  int	i;
  char	*check;

  i = 0;
  check = malloc(sizeof(char) * 16);
  if (check == NULL)
    return (NULL);
  while (av[n][i] != '=' && av[n][i] && i != 14)
    {
      check[i] = av[n][i];
      i++;
    }
  check[i] = av[n][i];
  i++;
  check[i] = 0;
  if (av[n][i] == 0)
    {
      if (check != NULL)
	free(check);
      return (NULL);
    }
  return (check);
}

char	*get_ag_for_double(char *check, char **av, int n)
{
  int	i;
  int	j;
  char	*ag;

  i = 0;
  j = 0;
  ag = malloc(sizeof(char) * 9);
  if (ag == NULL)
    return (NULL);
  while (check[i] != '=' && check[i] != 0)
    i++;
  if (check[i] == 0)
    return (NULL);
  i++;
  while (av[n][i] && j != 8)
    ag[j++] = av[n][i++];
  ag[j] = 0;
  return (ag);
}

int	check_double(char **av, int n, t_key *keys)
{
  int	i;
  char	*check;
  char	*ag;

  if ((check = get_check_for_double(av, n)) == NULL)
    return (-1);
  ag = get_ag_for_double(check, av, n);
  i = 0;
  while (i != 11)
    {
      if (my_strcmp(fct_key[i].key, check) == 0)
	return (fct_key[i].ptr(av, keys, n, ag));
      else if (fct_key[i].key2 != NULL &&
	       my_strcmp(fct_key[i].key2, check) == 0)
	return (fct_key[i].ptr(av, keys, n, ag));
      i++;
    }
  return (-1);
}

int	check_key(char **av, int n, t_key *keys)
{
  int	i;

  i = 0;
  if (av[n][0] == '-' && av[n][1] == '-' && my_strcmp(av[n], "--help") != 0)
    {
      if ((n = check_double(av, n, keys)) == -1)
	{
	  my_printf("Wrong argument(s) : type ./tetris ");
	  my_printf("--help for more details\n");
	  return (-1);
	}
      return (n);
    }
  while (i != 11)
    {
      if (my_strcmp(fct_key[i].key, av[n]) == 0)
	return (fct_key[i].ptr(av, keys, n, 0));
      else if (fct_key[i].key2 != NULL &&
	       my_strcmp(fct_key[i].key2, av[n]) == 0)
	return (fct_key[i].ptr(av, keys, n, 0));
      i++;
    }
  my_printf("Wrong argument(s) : type ./tetris --help for more details\n");
  return (-1);
}

int	check_options(char **av, char **env, t_key *keys)
{
  int	n;

  n = 1;
  while (av[n])
    {
      if ((n = check_key(av, n, keys)) == -1)
	return (-1);
      n++;
    }
  if (termcap(env, keys) == -1)
    return (-1);
  return (0);
}
