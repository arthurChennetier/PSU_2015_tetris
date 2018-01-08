/*
** map.h for tetris in /home/chenne_a/rendu/semestre2/PSU_2016/PSU_2015_tetris/map
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Wed Feb 24 17:59:33 2016 Arthur Chennetier
** Last update Sun Mar 20 18:46:06 2016 Arthur Chennetier
*/

#include <time.h>
#include <curses.h>
#include <sys/types.h>
#include <dirent.h>

#ifndef MAP_H_
# define MAP_H_

char	*buff;

//STRUCT

typedef struct  s_key
{
  int   level;
  char  *kl;
  char  *kr;
  char  *kt;
  char  *kd;
  char  *kq;
  char  *kp;
  int   row;
  int   col;
  int   without;
  int   d;
}               t_key;

typedef struct  s_fct_key
{
  char  *key;
  char  *key2;
  int   (*ptr)(char **av, t_key *keys, int n, char *arg);
}               t_fct_key;

typedef struct  s_tri
{
  int           *order;
  int           *panel;
  int           i;
  int           y;
  int           tmp;
  int           dif;
}               t_tri;

typedef struct  s_tetris
{
  int		color;
  int		height;
  int		width;
  char		*name;
  char		**piece;
}		t_tetris;

typedef struct		s_score
{
  int			high_score;
  int			actual_score;
  int			line;
  int			level;
  int			minutes;
  int			seconds;
  time_t		time;
  int			height;
  int			width;
  t_tetris		tetrimino;
  t_tetris		next;
}			t_score;

typedef struct		s_window
{
  WINDOW		*score;
  WINDOW		*title;
  WINDOW		*game;
  WINDOW		*next;
}			t_window;

typedef struct		s_game
{
  char			*game;
  int			*color;
  t_window		*all;
  int			idx;
  int			size;
  int			indic;
  t_key			*keys;
  t_score		*var;
  t_tetris		*piece;
}			t_game;

typedef struct		s_test
{
  int			i;
  int			nbr;
  int			divide;
  int			tmp;
}			t_test;

typedef struct		s_move
{
  int			tmp;
  int			pos;
  int			x;
  int			y;
}			t_move;

typedef struct		s_turn
{
  int			i;
  int			j;
  int			x;
  int			y;
  char			**tmp;
}			t_turn;

// FONCTIONS

//OPTIONS

int	change_map_free(char *row, char *col, int n);
int	change_level2(int level, char *arg, t_key *keys, int n);
int     check_key(char **av, int n, t_key *keys);
t_key   *init_keys(t_key *keys);
int     check_options(char **av, char **env, t_key *keys);
int     print_help(char **av, t_key *keys, int n, char *arg);
int     change_level(char **av, t_key *keys, int n, char *arg);
int     change_map(char **av, t_key *keys, int n, char *arg);
int     change_w(char **av, t_key *keys, int n, char *arg);
int     debug_on(char **av, t_key *keys, int n, char *arg);
int     change_left(char **av, t_key *keys, int n, char *arg);
int     change_right(char **av, t_key *keys, int n, char *arg);
int     change_turn(char **av, t_key *keys, int n, char *arg);
int     change_drop(char **av, t_key *keys, int n, char *arg);
int     change_quit(char **av, t_key *keys, int n, char *arg);
int     change_pause(char **av, t_key *keys, int n, char *arg);
int     check_special_key(char *arg, int key);
int     termcap(char **env, t_key *keys);
int     *init_panel(int size);
int     my_tri_strcmp(char *str1, char *str2);
void    tri_algo(t_tri *tri, t_tetris *piece, int size);
int     tetriminos_option();
int     *my_tri(t_tetris *piece, int size);
void    my_free(t_key *keys);
void    print_piece(char **piece);
void    print_tetriminos(t_tetris *piece, int *order, int size);
void    print_piece(char **piece);

// MAP

void			clear_case(t_game *ctx, t_move var);
int			delay_passed(t_game *ctx);
int			check_under_tetri(t_game *ctx);
void			my_bzero(char *str, int size);
int			init_tab(char *game, int *color, t_tetris *next, t_tetris *piece);
int			game(t_game *ctx);
t_tetris		*fill_tetriminos(t_tetris *piece, DIR *dir, int i);
char			*my_path(char *name);
char			**make_piece(char *name, char **piece, t_tetris info);
t_tetris		*init_tetrimino();
char			*read_tetrimino(char *name);
t_tetris		check_tetrimino(char *name);
int			algo_dimensions(char *name, int i, t_tetris info);
int			test_dimensions(t_tetris info, char *name);
int			width_init(char *name);
int			height_init(char *name);
int			color_init(char *name);
int			begin_color(char *name);
t_tetris		error_piece(t_tetris info);
int			refresh_game(t_score *var, t_window *all, t_key *keys, t_tetris *piece);
void			refresh_time(t_score *var);
int			launch_tetris(t_key *keys);
int			init_var(t_score *var, t_key *keys, t_tetris *piece, int size);
void			display_time(WINDOW *score, t_score *var);
void			display_space_score(WINDOW *score, t_score *var);
void			refresh_map(t_window *all, t_score *var);
int			display_all(t_window *all, t_score *var, int without);
void			display_T(WINDOW *title);
void			display_E(WINDOW *title);
void			display_second_T(WINDOW *title);
void			display_R(WINDOW *title);
void			display_I(WINDOW *title);
void			display_title(WINDOW *title);
void			display_score(WINDOW *score, t_score *var);
void			display_game(WINDOW *game, t_score *var);
void			display_next(WINDOW *next, t_score *var);
void			display_S(WINDOW *title);
int			create_map(WINDOW *win, t_score *var, t_window *all, int without);
void			display_game2(WINDOW *game, t_score *var);
int                     mod(int i);
t_game			*init_game_tab(t_score *var, t_window *all, t_key *keys, t_tetris *piece);
char			*init_game(t_key *keys);
int			*init_tab_color(t_key *keys);
int			user_key(t_game *ctx);
int			check_tetri(t_game *ctx, int idx);
int			clear_tetri(t_game *ctx);
int			add_tetri(t_game *ctx);
t_move			algo_add(t_game *ctx, t_move var);
int			move_piece(t_game *ctx);
void			color_ini();
int			key_pause(t_game *ctx);
int			turn_move(t_game *ctx);
int			move_down_plat(t_game *ctx, int i, int j);
int			get_high_score();
int			write_high_score(int score);
int			turn_change_param(t_turn *var, t_game *ctx);
int			check_err(int err, t_game *ctx, int indic);
int			end_high_score(t_game *ctx);

#endif /* !MAP_H_ */
