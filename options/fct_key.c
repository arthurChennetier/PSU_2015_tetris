/*
** fct_key.c for tetris in /home/chauvi_d/Rendu-2015-Epitech/rendu/Systunix/PSU_2015_tetris/options
** 
** Made by chauvi_d
** Login   <chauvi_d@epitech.net>
** 
** Started on  Thu Feb 25 15:54:19 2016 chauvi_d
** Last update Wed Mar  9 13:43:20 2016 chauvi_d
*/

#include "map.h"
#include "my.h"

int	change_turn(char **av, t_key *keys, int n, char *arg)
{
  if (av[n][0] == '-' && av[n][1] != '-')
    {
      if (av[n + 1] != NULL)
	keys->kt = my_strcpy(keys->kt, av[n + 1]);
      else
	{
	  my_printf("Wrong arguments : type ./tetris --help for more details\n");
	  return (-1);
	}
      n++;
    }
  else if (arg != NULL)
    keys->kt = my_strcpy(keys->kq, arg);
  return (n);
}

int	change_quit(char **av, t_key *keys, int n, char *arg)
{
  if (av[n][0] == '-' && av[n][1] != '-')
    {
      if (av[n + 1] != NULL)
	keys->kq = my_strcpy(keys->kq, av[n + 1]);
      else
	{
	  my_printf("Wrong arguments : type ./tetris --help for more details\n");
	  return (-1);
	}
      n++;
    }
  else if (arg != NULL)
    keys->kq = my_strcpy(keys->kq, arg);
  return (n);
}

int	change_pause(char **av, t_key *keys, int n, char *arg)
{
  if (av[n][0] == '-' && av[n][1] != '-')
    {
      if (av[n + 1] != NULL)
	keys->kp = my_strcpy(keys->kp, av[n + 1]);
      else
	{
	  my_printf("Wrong arguments : type ./tetris --help for more details\n");
	  return (-1);
	}
      n++;
    }
  else if (arg != NULL)
    keys->kp = my_strcpy(keys->kp, arg);
  return (n);
}
