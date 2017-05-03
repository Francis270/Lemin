/*
** my_lenghts.c for lib in /home/francis/Documents/new_project/src/lib/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Tue Mar 28 15:58:07 2017 Francois Caicedo
** Last update Mon Apr 10 17:40:35 2017 Clément Poirier
*/

#include "lib.h"

int		my_strlen(const char *s)
{
  size_t	len;

  len = INIT_ZERO;
  if (s == NULL)
    return (len);
  while (s[len++]);
  return (len - 1);
}

int		my_tablen(const char **tab)
{
  size_t	len;

  len = INIT_ZERO;
  if (tab == NULL)
    return (len);
  while (tab[len++]);
  return (len);
}

int		my_inttab_len(const int *ptr, int size)
{
  int		len;

  len = INIT_NEG;
  if (ptr == NULL)
    return (len);
  while (++len != size);
  return (len);
}

int		size_of_nb(int nb)
{
  int	i;

  i = 1;
  while (nb != 0)
    {
      nb = nb / 10;
      if (nb != 0)
	i++;
    }
  return (i);
}
