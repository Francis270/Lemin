/*
** my_xlib.c for lib in /home/francis/Documents/CPE/CPE_2016_Lemin/src/lib/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Sat Apr  8 23:17:21 2017 Francois Caicedo
** Last update Wed Apr 12 15:19:50 2017 Francois Caicedo
*/

#include "lib.h"

int		xfree(void *ptr)
{
  if (ptr)
    free(ptr);
  return (0);
}

void		*xmalloc(size_t	size)
{
  void		*ptr;

  if (size == 0)
    return (NULL);
  if ((ptr = malloc(size)) == NULL)
    return (write(2, MALLOC_ERROR, my_strlen(MALLOC_ERROR)), NULL);
  return (ptr);
}
