/*
** my_free.c for tetris in /home/chauvi_d/Rendu-2015-Epitech/rendu/Systunix/PSU_2015_tetris
** 
** Made by chauvi_d
** Login   <chauvi_d@epitech.net>
** 
** Started on  Mon Mar  7 11:58:29 2016 chauvi_d
** Last update Wed Mar  9 13:45:08 2016 chauvi_d
*/

#include <unistd.h>
#include "map.h"
#include "my.h"

void	my_free(t_key *keys)
{
  if (keys->kl != NULL)
    free(keys->kl);
  if (keys->kr != NULL)
    free(keys->kr);
  if (keys->kt != NULL)
    free(keys->kt);
  if (keys->kd != NULL)
    free(keys->kd);
  if (keys->kq != NULL)
    free(keys->kq);
  if (keys->kp != NULL)
    free(keys->kp);
  free(keys);
}
