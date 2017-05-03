/*
** lib.h for lemin in /home/francis/Documents/CPE/CPE_2016_Lem-In/include/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Sat Apr  1 22:44:55 2017 Francois Caicedo
** Last update Thu Apr 13 00:44:37 2017 Francois Caicedo
*/

#ifndef LIB_H_
# define LIB_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

#define READ_SIZE (1024)
#define INIT_NULL (NULL)
#define INIT_NEG (-1)
#define INIT_ZERO (0)
#define INIT_ONE (1)

#define MALLOC_ERROR ("Memory allocation error...\n")
#define DASH ('-')
#define HASHTAG ('#')
#define SPACE (' ')
#define SPACES (" ")
#define NLINE ('\n')
#define TAB ('\t')
#define PLUS ('+')
#define ZERO ('0')
#define NINE ('9')

int		my_strcmp(const char *s1, const char *s2);
int		my_strncmp(const char *s1, const char *s2, size_t n);
int		my_strisnum(const char *str);
int		my_str_is_alphanum(const char *str);

char		*my_strcpy(char *dest, const char *src);
char		*my_strcat(char *dest, const char *src);
char		*my_strdup(char *str);
char		*rewrite_spaces(char *com, char *first, char *second, int len);
char		*epur(char *str);

char		*my_strncpy(char *dest, const char *src, int n);
char		*strncut_before(char *str, size_t n);
char		*my_strncat(char *dest, const char *src, size_t n);
char		*my_strndup(char *str, size_t n);

void		my_free_2dc(char **ptr);
void		my_show_2dc(char **ptr);
char		**my_str_to_wordtab(const char *s, const char n);

void		my_free_2di(int **ptr);
void		my_show_2di(int **ptr);

int		my_fd_len(const int fd);
int		my_getnbr(const char *str);
char		*get_next_line(const int fd, int lenght, int need_realloc);

int		my_strlen(const char *s);
int		my_tablen(const char **tab);
int		my_inttab_len(const int *ptr, int size);
int		size_of_nb(int nb);

int		my_putchar(const char c, unsigned int output);
int		my_putstr(const char *s, unsigned int output);
int		my_putnbr(int nb, unsigned int output);
void		my_printf(char *str, ...);

int		rand_x_y(const int min, const int max);

int		my_free(void *ptr);
char		*my_realloc_1dc(char *ptr, size_t size);
char		**my_realloc_2dc(char **ptr, size_t size);
int		*my_realloc_1di(int *ptr, size_t size);
int		**my_realloc_2di(int **ptr, size_t size);

void		*xmalloc(size_t	size);
int		xfree(void *ptr);

#endif /* !LIB_H_ */
