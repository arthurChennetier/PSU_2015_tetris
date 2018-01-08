/*
** keybind.c for tetris in /home/chauvi_d/Rendu-2015-Epitech/rendu/Systunix/PSU_2015_tetris/options
** 
** Made by chauvi_d
** Login   <chauvi_d@epitech.net>
** 
** Started on  Thu Mar  3 14:27:11 2016 chauvi_d
** Last update Tue Mar 15 13:07:06 2016 chauvi_d
*/

#include <curses.h>
#include "map.h"
#include "my.h"

int     change_left(char **av, t_key *keys, int n, char *arg)
{
  if (av[n][0] == '-' && av[n][1] != '-')
    {
      if (av[n + 1] != NULL)
	keys->kl = my_strcpy(keys->kl, av[n + 1]);
      else
	{
	  my_printf("Wrong arguments : type ./tetris --help for more details\n");
	  return (-1);
	}
      n++;
    }
  else if (arg != NULL)
    keys->kl = my_strcpy(keys->kl, arg);
  return (n);
}

int     change_right(char **av, t_key *keys, int n, char *arg)
{
  if (av[n][0] == '-' && av[n][1] != '-')
    {
      if (av[n + 1] != NULL)
	keys->kr = my_strcpy(keys->kr, av[n + 1]);
      else
	{
	  my_printf("Wrong arguments : type ./tetris --help for more details\n");
	  return (-1);
	}
      n++;
    }
  else if (arg != NULL)
    keys->kr = my_strcpy(keys->kr, arg);
  return (n);
}

int     change_drop(char **av, t_key *keys, int n, char *arg)
{
  if (av[n][0] == '-' && av[n][1] != '-')
    {
      if (av[n + 1] != NULL)
	keys->kd = my_strcpy(keys->kd, av[n + 1]);
      else
	{
	  my_printf("Wrong arguments : type ./tetris --help for more details\n");
	  return (-1);
	}
      n++;
    }
  else if (arg != NULL)
    keys->kd = my_strcpy(keys->kd, arg);
  return (n);
}

t_key	*init_keys(t_key *keys)
{
  keys = malloc(sizeof(t_key));
  if (keys == NULL)
    return (NULL);
  keys->d = 0;
  keys->kl = NULL;
  keys->kr = NULL;
  keys->kt = NULL;
  keys->kd = NULL;
  keys->kq = NULL;
  keys->kp = NULL;
  keys->without = 1;
  keys->level = 1;
  keys->row = 20;
  keys->col = 10;
  return (keys);
}
