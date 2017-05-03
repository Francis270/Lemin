/*
** my_1dcn_utils.c for lib in /home/francis/Documents/new_project/src/lib/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Tue Mar 28 16:24:28 2017 Francois Caicedo
** Last update Tue Apr  4 09:37:51 2017 Francois Caicedo
*/

#include "lib.h"

char		*my_strncpy(char *dest, const char *src, int n)
{
  int		len;

  len = INIT_NEG;
  while (src[++len] && len < n)
    dest[len] = src[len];
  dest[len] = INIT_ZERO;
  return (dest);
}

char		*strncut_before(char *str, size_t n)
{
  char		*tmp;
  size_t	i;
  size_t	j;

  tmp = str;
  if ((str = malloc(sizeof(char) * (my_strlen(tmp) + 1))) == NULL)
    return (NULL);
  i = n;
  j = INIT_ZERO;
  while (tmp[i])
    str[j++] = tmp[i++];
  str[j] = INIT_ZERO;
  return (str);
}

char		*my_strncat(char *dest, const char *src, size_t n)
{
  size_t	len;
  size_t	src_len;

  len = INIT_ZERO;
  src_len = my_strlen(src);
  while (src[len++] && len < n)
    dest[src_len + len] = src[len];
  dest[src_len + len] = INIT_ZERO;
  return (dest);
}
