/*
** list.c for list in /home/francis/Documents/CPE/CPE_2016_Lemin/src/lib/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Thu Apr  6 10:20:14 2017 Francois Caicedo
** Last update Thu Apr  6 10:38:35 2017 Francois Caicedo
*/

#include "lib.h"

t_list		*create_list()
{
  t_list	*new;

  if ((new = malloc(sizeof *new)) == NULL)
    return (NULL);
  new->len = INIT_ZERO;
  new->first = INIT_NULL;
  new->last = INIT_NULL;
  return (new);
}
