/*
** libmy.h for libmy.h in /home/chauvi_d/rendu/Piscine_C_J07/lib/my
** 
** Made by Chauvin Antoine
** Login   <chauvi_d@epitech.net>
** 
** Started on  Wed Oct  7 16:15:53 2015 Chauvin Antoine
** Last update Fri Mar 18 15:54:27 2016 Chauvin Antoine
*/

#ifndef	MY_H_
# define MY_H_

#include <stdarg.h>
#include <stdlib.h>
# define ERROR_MSG "error\n"
# define SYNTAXE_ERROR_MSG "syntax error"

typedef struct s_fonction
{
  char  flag;
  int   (*ptr)(va_list);
}              t_fonction;

int     my_putchar_va(va_list c);
int     my_putchar_pourcent(va_list);
int     my_put_nbr_va(va_list c);
int     my_put_nbrbase(int nb, char *base);
int     my_put_base(va_list c);
int     my_put_adress(va_list c);
int     my_put_unsbase(unsigned int nb, char *base);
int     my_put_oct(va_list c);
int     my_put_hex(va_list c);
int     my_put_hexup(va_list c);
int     my_put_bin(va_list c);
int     my_put_uns_va(va_list c);
int     my_putstr_va(va_list c);
int     my_putstr_ascii(va_list c);
int     my_printf(const char *format, ...);
void	my_putchar(char c);
int	my_put_nbr(int nb);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
char	**str_to_word_tab(char *str, char CHAR);
char	*my_realloc(char *str, int size);
char    *strcat(char *str1, char *str2);
void	free_2d(char **str);
int	my_strcmp(const char *str1, const char *str2);
char	*word_tab_to_str(char **str);
char    *get_nb_words(char **str);
char	*my_revstr(char *str);
unsigned int	bin_to_str(char *bin);
char	*str_to_bin(unsigned int nb);
char	*pid_to_bin(unsigned int nb);
char	*my_strcpy(char *dest, char *src);

#endif /* !MY_H_ */
