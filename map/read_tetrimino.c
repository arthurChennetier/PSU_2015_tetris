/*
** read_tetrimino.c for tetris in /home/chenne_a/rendu/semestre2/PSU_2016/PSU_2015_tetris/tetriminos
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Mon Feb 22 10:41:23 2016 Arthur Chennetier
** Last update Wed Mar 16 17:38:46 2016 Arthur Chennetier
*/

#include <curses.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "my.h"
#include "map.h"

char		*read_tetrimino(char *name)
{
  char		*file;
  int		fd;
  int		size;

  if ((file = malloc(sizeof(char) * 50)) == NULL)
    return (NULL);
  if ((name = my_path(name)) == NULL)
    return (NULL);
  if ((fd = open(name, O_RDONLY)) == -1)
    return (NULL);
  size = read(fd, file, 50);
  file[size] = '\0';
  return (file);
}

char		**make_piece(char *name, char **piece, t_tetris info)
{
  int		i;
  int		y;
  int		j;

  y = 0;
  j = 0;
  if ((i = test_dimensions(info, name)) == -1)
    return (NULL);
  while (name[i] != '\0')
    {
      while (name[i] != '\n' && name[i] != '\0')
	{
	  if (name[i] != '*' && name[i] != ' ')
	    return (NULL);
	  piece[j][y++] = name[i++];
	}
      while (y < info.width)
	piece[j][y++] = ' ';
      piece[j++][y] = '\0';
      i = i + 1;
      y = 0;
    }
  return (piece);
}

t_tetris	check_tetrimino(char *name)
{
  t_tetris	info;
  int		i;

  i = 0;
  if (name == NULL)
    exit(EXIT_FAILURE);
  if (name[0] < '1' || name[0] > '9')
    return (error_piece(info));
  info.width = width_init(name);
  info.height = height_init(name);
  info.color = color_init(name);
  if ((info.piece = malloc(sizeof(char*) * (info.height + 1))) == NULL)
    exit(EXIT_FAILURE);
  while (i < info.height)
    {
      if ((info.piece[i] = malloc(sizeof(char) * (info.width + 1))) == NULL)
	exit(EXIT_FAILURE);
      i = i + 1;
    }
  info.piece[i] = NULL;
  if (info.width != 0 && info.height != 0)
    info.piece = make_piece(name, info.piece, info);
  else
    info.piece = NULL;
  return (info);
}

t_tetris		*fill_tetriminos(t_tetris *piece, DIR *dir, int i)
{
  struct dirent		*info;
  int			y;

  y = 0;
  while (y < i)
    {
      info = readdir(dir);
      if (info->d_name != NULL)
	{
	  if (info->d_name[0] != '.')
	    {
	      piece[y] = check_tetrimino(read_tetrimino(info->d_name));
	      if ((piece[y].name =
		   malloc(sizeof(char) *
			  (my_strlen(info->d_name) + 1))) == NULL)
		return (NULL);
	      piece[y].name = my_strcpy(piece[y].name, info->d_name);
	      y = y + 1;
	    }
	  else
	    i = i - 1;
	}
    }
  piece[y] = error_piece(piece[y]);
  return (piece);
}

t_tetris		*init_tetrimino()
{
  t_tetris		*piece;
  int			i;
  DIR			*dir;

  i = 0;
  if ((dir = opendir("./tetriminos")) == NULL)
    return (NULL);
  while (readdir(dir) != NULL)
    i = i + 1;
  if (closedir(dir) == -1)
    return (NULL);
  if ((piece = malloc(sizeof(t_tetris) * (i + 1))) == NULL)
    return (NULL);
  if ((dir = opendir("./tetriminos")) == NULL)
    return (NULL);
  if ((piece = fill_tetriminos(piece, dir, i)) == NULL)
    return (NULL);
  if (closedir(dir) == -1)
    return (NULL);
  return (piece);
}
