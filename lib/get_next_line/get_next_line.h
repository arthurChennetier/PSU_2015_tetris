/*
** get_next_line.h for get_next_line in /home/chenne_a/rendu/CPE_2015_getnextline
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Mon Jan  4 09:35:30 2016 Arthur Chennetier
** Last update Mon Feb 15 15:37:07 2016 Arthur Chennetier
*/

#ifndef				GET_NEXT_LINE_H_
# define			 GET_NEXT_LINE_H_

# ifndef			READ_SIZE
#  define			 READ_SIZE (4096)
# endif	/* !READ_SIZE! */

char	*get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H */
