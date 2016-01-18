#ifndef FILLIT_H
# define FILLIT_H
# define BUF_SIZE 1 
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct	s_var
{
  int count;
  int length;
  char *chaine;
  char *piece;
}				t_var;

typedef struct  s_var2
{
  char carac;
  int tetri;
  int nbt;
  char *chaine;
  int length;
  
}                               t_var2;

int             try_1(char *chaine);
int             try_2(char *chaine, int count, int time, int i);
int             try_3(char *chaine, int count, int time, int i);
int             try_f(char *chaine, int i);
int             try_4(char *chaine);
int             all_try(char *chaine);
int             right(char *chaine, int i, int count);
int             down(char *chaine, int i, int count);
int            up(char *chaine, int i, int count);
int             left(char *chaine, int i, int count);
char    *dp(const char *s1);
size_t  ft_strlen(const char *str);
void    ft_putchar(char c);
void    ft_putstr(char const *str);
char    *ft_strdup(const char *s1);
int     go_right(int chainei, int piecei, t_var *var);
int     go_down(int chainei, int piecei, t_var *var);
int     go_up(int chainei, int piecei, t_var *var);
int     go_left(int chainei, int piecei, t_var *var);
int     backtrack(int *iactuel, char **tab, t_var2 *var2);
int ft_test_form(char *piece);
void ft_all(char *piece);
void    v_2(t_var2 *var2, int *iactuel);
void    v_0(t_var2 *var2, int *iactuel);
int             first_di(char *piece);
void    p_c_change(t_var *var, int chainei, int piecei);
int             try(char *piece, char *chaine, int chainei, int length);
char    **all_tetri(char *chaine, int i, int index, int i2);
char    *malloc_chaine(char *chaine, int length);
int             first_di(char *piece);
int             *iactuel_reset(int *iactuel, int nbt);
char *trans_di(char *chaine, char c);
int             nb_tetri(char *chaine);
#endif
