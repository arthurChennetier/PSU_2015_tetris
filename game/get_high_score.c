/*
** get_high_socre.c for get_high_score.c in /home/chauvi_d/Rendu-2015-Epitech/rendu/Systunix/PSU_2015_tetris/game
** 
** Made by chauvi_d
** Login   <chauvi_d@epitech.net>
** 
** Started on  Wed Mar 16 13:49:25 2016 chauvi_d
** Last update Sun Mar 20 18:22:25 2016 chauvi_d
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <curses.h>
#include "map.h"
#include "my.h"

char	*my_get_score(int nb)
{
  int   result;
  int   divisor;
  char	*str;
  int	i;

  i = 0;
  divisor = 1;
  if ((str = malloc(sizeof(char) * 6)) == NULL)
    return (NULL);
  if (nb < 0)
    return (NULL);
  while ((nb / divisor) >= 10)
    divisor = divisor * 10;
  while (divisor > 0)
    {
      result = (nb / divisor) % 10;
      str[i] = 48 + result;
      divisor = divisor / 10;
      i++;
    }
  while (i != 6)
    str[i++] = 0;
  return (str);
}

int	check_content(char *buff)
{
  int	i;

  i = 0;
  while (buff[i])
    {
      if (buff[i] < '0' || buff[i] > '9')
	{
	  write(2, "Wrong Highscore file\n", 21);
	  return (-1);
	}
      i++;
    }
  return (0);
}

int     get_high_score()
{
  char  *buff;
  int   fd;
  int   i;

  i = 0;
  buff = malloc(sizeof(char) * 6);
  if (buff == NULL)
    return (-1);
  fd = open("./game/.highscore", O_RDONLY | O_CREAT);
  if (fd == -1)
    {
      write(2, "Highscore file is missing\n", 28);
      return (-1);
    }
  i = read(fd, buff, 5);
  buff[i] = 0;
  if (check_content(buff) == -1)
    return (-1);
  i = my_getnbr(buff);
  if (i > 200000)
    return (-1);
  return (i);
}

int     write_high_score(int score)
{
  int	fd;
  char	*highscore;

  if (score > get_high_score())
    {
      if ((fd = open("./game/.highscore", O_WRONLY)) == -1)
	{
	  write(2, "Highscore file is missing\n", 28);
	  return (-1);
	}
      highscore = my_get_score(score);
      write(fd, highscore, my_strlen(highscore) + 1);
      close(fd);
    }
  return (0);
}
