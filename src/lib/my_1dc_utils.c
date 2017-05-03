/*
** my_1dc_utils.c for lib in /home/francis/Documents/new_project/src/lib/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Tue Mar 28 16:09:36 2017 Francois Caicedo
** Last update Tue Apr  4 09:36:22 2017 Francois Caicedo
*/

#include "lib.h"

char		*my_strcpy(char *dest, const char *src)
{
  int		len;

  len = INIT_NEG;
  while (src[++len])
    dest[len] = src[len];
  dest[len] = INIT_ZERO;
  return (dest);
}

char		*my_strcat(char *dest, const char *src)
{
  int		len;
  size_t	src_len;

  len = INIT_NEG;
  src_len = my_strlen(src);
  while (src[++len])
    dest[src_len + len] = src[len];
  dest[src_len + len] = INIT_ZERO;
  return (dest);
}

char		*my_strdup(char *str)
{
  char		*new_mem;

  if ((new_mem = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  new_mem = my_strcpy(new_mem, str);
  return (new_mem);
}

char		*rewrite_spaces(char *com, char *first, char *second, int len)
{
  int		i;
  int		j;

  if ((first = malloc(len + 1)) == NULL || (second = malloc(len + 1)) == NULL)
    return (NULL);
  i = j = INIT_NEG;
  while (com[++i])
    {
      if (com[i] == DASH && com[i - 1] != SPACE)
	break;
      else
	first[i] = com[i];
    }
  first[i] = INIT_ZERO;
  if (i == len)
    return (free(first), free(second), com);
  i--;
  while (com[++i])
    second[++j] = com[i];
  second[++j] = INIT_ZERO;
  if ((com = malloc(sizeof(char) * (len + 2))) == NULL)
    return (NULL);
  com = my_strcat(my_strcpy(com, first), SPACES);
  com = my_strcat(com, second);
  return (free(first), free(second), com);
}

char		*epur(char *str)
{
  char		*tmp;
  int		i;
  int		j;

  if ((tmp = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  i = INIT_NEG;
  j = INIT_ZERO;
  if (str[0] == SPACE)
    str = strncut_before(str, 1);
  if (str[my_strlen(str)] == SPACE)
    str = my_strncpy(str, str, 1);
  while (str[++i])
    {
      if (str[i] != TAB)
	tmp[j++] = str[i];
    }
  tmp[j] = INIT_ZERO;
  free(str);
  return (tmp);
}
