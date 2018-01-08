/*
** main.c for main in /home/chauvi_d/Rendu-2015-Epitech/rendu/Systunix/PSU_2015_tetris
** 
** Made by chauvi_d
** Login   <chauvi_d@epitech.net>
** 
** Started on  Mon Feb 22 10:42:19 2016 chauvi_d
** Last update Thu Mar 17 16:03:48 2016 chauvi_d
*/

#include <stdlib.h>
#include <unistd.h>
#include <curses.h>
#include <termios.h>
#include <sys/ioctl.h>
#include "my.h"
#include "map.h"

int			mod(int i)
{
  static struct termios	oldT;
  static struct termios	newT;

  if (i == 0 || i == 2)
    {
      if (ioctl(0, TCGETS, &oldT) == -1)
	return (-1);
      if (ioctl(0, TCGETS, &newT) == -1)
	return (-1);
      newT.c_lflag &= ~ICANON;
      if (i == 0)
	{
	  newT.c_cc[VMIN] = 0;
	  newT.c_cc[VTIME] = 0;
	}
      ioctl(0, TCSETS, &newT);
    }
  if (i == 1)
    {
      if (ioctl(0, TCSETS, &oldT) == -1)
	return (-1);
    }
  return (0);
}

void	debug_mode(t_key *keys)
{
  my_printf("*** DEBUG MODE ***\n");
  my_printf("Key Left : %s\n", keys->kl);
  my_printf("Key Right : %s\n", keys->kr);
  my_printf("Key Turn : %s\n", keys->kt);
  my_printf("Key Drop : %s\n", keys->kd);
  my_printf("Key Quit : %s\n", keys->kq);
  my_printf("Key Pause : %s\n", keys->kp);
  if (keys->without == 1)
    my_printf("Next : Yes\n");
  else
    my_printf("Next : No\n");
  my_printf("Level : %d\n", keys->level);
  my_printf("Size : %d*%d\n", keys->row, keys->col);
  tetriminos_option();
  my_printf("Press a key to start Tetris\n");
  mod(2);
  read(0, NULL, 1);
}

int	main(int ac, char **av, char **env)
{
  t_key	*keys;

  keys = NULL;
  keys = init_keys(keys);
  if (check_options(av, env, keys) == -1 && ac > 1)
    return (-1);
  if (keys->d == 1)
    {
      debug_mode(keys);
      mod(1);
    }
  if (launch_tetris(keys) == -1)
    {
      mod(1);
      endwin();
      return (-1);
    }
  my_free(keys);
  return (0);
}
