/*
** my_1d_comp.c for lib in /home/francis/Documents/new_project/src/lib/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Tue Mar 28 17:00:14 2017 Francois Caicedo
** Last update Mon Apr 10 16:34:33 2017 Clément Poirier
*/

#include "lib.h"

int		my_strcmp(const char *s1, const char *s2)
{
  size_t	len;

  len = INIT_ZERO;
  while (s1[len] == s2[len] && s1[len])
    len++;
  return (s1[len] - s2[len]);
}

int		my_strncmp(const char *s1, const char *s2, size_t n)
{
  size_t	len;

  len = INIT_ZERO;
  while (s2[len] && len < n)
    {
      if ((s1[len] != s2[len]) || s1 == NULL || s2 == NULL)
	return (1);
      len++;
    }
  return (0);
}

int		my_strisnum(const char *str)
{
  int		len;

  len = INIT_NEG;
  while (str[++len])
    {
      if (str[len] < '0' || str[len] > '9')
	return (-1);
    }
  return (0);
}

int		my_str_is_alphanum(const char *str)
{
  int		len;

  len = INIT_NEG;
  while (str[++len])
    {
      if ((str[len] < 'a' || str[len] > 'z') &&
	  (str[len] < 'A' || str[len] > 'Z') &&
	  (str[len] < '0' || str[len] > '9'))
	return (-1);
    }
  return (0);
}

int		my_char_is_alphanum(const char c)
{
  if ((c < 'a' || c > 'z') &&
      (c < 'A' || c > 'Z') &&
      (c < '0' || c > '9'))
    return (-1);
  return (0);
}
