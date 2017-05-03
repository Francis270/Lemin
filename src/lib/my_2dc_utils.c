/*
** my_2dc_utils.c for lib in /home/francis/Documents/new_project/src/lib/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Tue Mar 28 15:53:01 2017 Francois Caicedo
** Last update Tue Apr 11 13:21:22 2017 Clément Poirier
*/

#include "lib.h"

void		my_free_2dc(char **ptr)
{
  int		i;

  i = INIT_NEG;
  while (ptr[++i])
    free(ptr[i]);
  free(ptr);
}

void		my_show_2dc(char **ptr)
{
  int		i;

  i = 0;
  while (ptr[i])
    {
      my_printf("%s\n", 1, ptr[i]);
      i++;
    }
}

int		count_word(const char *str, const char n)
{
  unsigned int	nb;
  int		i;

  i = INIT_NEG;
  nb = INIT_ONE;
  while (str[++i])
    {
      if (str[i] == n)
	nb++;
    }
  return (nb);
}

int		word_len(const char *str, const char n, size_t len)
{
  unsigned int	nb;

  nb = INIT_ZERO;
  while (str[len] != n && str[len])
    {
      nb++;
      len++;
    }
  return (nb);
}

char		**my_str_to_wordtab(const char *s, const char n)
{
  char		**wordtab;
  size_t	i;
  size_t	j;
  size_t	k;

  i = INIT_ZERO;
  j = INIT_ZERO;
  if ((wordtab = malloc(sizeof(char *) * ((count_word(s, n) + 1)))) == NULL)
    return (NULL);
  while (s[i++] == n);
  while (s[i])
    {
      k = INIT_ZERO;
      if ((wordtab[j] = malloc(sizeof(char) * word_len(s, n, i) + 1)) == NULL)
	return (NULL);
      while (s[i] != n && s[i])
	wordtab[j][k++] = s[i++];
      wordtab[j++][k] = INIT_ZERO;
      while (s[i++] == n);
    }
  wordtab[j] = INIT_ZERO;
  return (wordtab);
}
