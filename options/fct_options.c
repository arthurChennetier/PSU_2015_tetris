/*
** fct_key.c for tetris in /home/chauvi_d/Rendu-2015-Epitech/rendu/Systunix/PSU_2015_tetris/options
** 
** Made by chauvi_d
** Login   <chauvi_d@epitech.net>
** 
** Started on  Thu Feb 25 15:11:43 2016 chauvi_d
** Last update Thu Mar 17 17:27:42 2016 Arthur Chennetier
*/

#include <unistd.h>
#include "my.h"
#include "map.h"

int	print_help(char **av, t_key *keys, int n, char *arg)
{
  my_printf("Usage: %s [options]\nOptions:\n", av[0]);
  my_printf("  --help                 Display this help\n");
  my_printf("  -l --level={num}       Start Tetris at level num\n");
  my_printf("  -kl --key-left={K}     Move tetrimino on LEFT with key K\n");
  my_printf("  -kr --key-right={K}    Move tetrimino on RIGHT with key K\n");
  my_printf("  -kt --key-turn={K}     Turn tetrimino with key K\n");
  my_printf("  -kd --key-drop={K}     Set default DROP on key K\n");
  my_printf("  -kq --key-quit={K}     Quit program when press key K\n");
  my_printf("  -kp --key-pause={K}    Pause and restart game ");
  my_printf("when press key K\n");
  my_printf("  --map-size={row,col}   Set game size at row, col\n");
  my_printf("  -w --without-next      Hide next tetrimino\n");
  my_printf("  -d --debug             Debug mode\n");
  av = av;
  keys = keys;
  n = n;
  arg = arg;
  return (-1);
}

int	change_level(char **av, t_key *keys, int n, char *arg)
{
  int	level;

  level = 0;
  if (av[n][0] == '-' && av[n][1] != '-')
    {
      if (av[n + 1] != NULL && (av[n + 1][0] >= '1' && av[n + 1][0] <= '9'))
	level = my_getnbr(av[n + 1]);
      else
	{
	  my_printf("Wrong Arguments : type ./tetris --help for more details\n");
	  return (-1);
	}
      if (level == 0 || level > 20)
	{
	  my_printf("Wrong level (max 20)\n");
	  return (-1);
	}
      keys->level = level;
      n++;
    }
  else
    return (change_level2(level, arg, keys, n));
  return (n);
}

int	change_map(char **av, t_key *keys, int n, char *arg)
{
  char	*row;
  char	*col;
  int	i;
  int	j;

  i = 0;
  j = 0;
  av = av;
  if ((row = malloc(sizeof(char) * my_strlen(arg) + 1)) == NULL)
    return (-1);
  if ((col = malloc(sizeof(char) * my_strlen(arg) + 1)) == NULL)
    return (-1);
  while (arg[i] != ',')
    {
      row[i] = arg[i];
      i++;
    }
  row[i] = 0;
  i++;
  while (arg[i])
    col[j++] = arg[i++];
  col[j] = 0;
  keys->row = my_getnbr(row);
  keys->col = my_getnbr(col);
  return (change_map_free(row, col, n));
}

int	change_w(char **av, t_key *keys, int n, char *arg)
{
  av = av;
  keys = keys;
  n = n;
  arg = arg;
  keys->without = 0;
  return (n);
}

int	debug_on(char **av, t_key *keys, int n, char *arg)
{
  av = av;
  keys = keys;
  n = n;
  arg = arg;
  keys->d = 1;
  return (n);
}
