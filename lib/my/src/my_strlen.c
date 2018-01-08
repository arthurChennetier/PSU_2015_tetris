/*
** my_strlen.c for my_strlen.c in /home/chauvi_d/rendu/day04
** 
** Made by Chauvin Antoine
** Login   <chauvi_d@epitech.net>
** 
** Started on  Thu Oct  1 16:34:28 2015 Chauvin Antoine
** Last update Mon Oct 19 11:14:52 2015 Chauvin Antoine
*/

int	my_strlen(char *str)
{
  int count;

  count = 0;
  while (str[count] != '\0')
    count  = count + 1;
  return (count);
}
