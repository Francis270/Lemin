/*
** list_tetrimino.c for lem_in in /home/clement/projects/Epitech/C_Prog_Elem/Lem_in/CPE_2016_Lemin/src/parsing/
**
** Made by Clément Poirier
** Login   <Poirie_c@epitech.net>
**
** Started on  Mon Apr 10 16:10:39 2017 Clément Poirier
** Last update Wed Apr 12 16:20:19 2017 Clément Poirier
*/

#include "lib.h"
#include "lemin.h"
#include "parsing.h"

t_list		*new_list()
{
  t_list	*new_list;

  if ((new_list = malloc(sizeof *new_list)) == NULL)
    return NULL;
  new_list->lenght = 0;
  new_list->first = NULL;
  new_list->last = NULL;
  return (new_list);
}

void		free_node(t_rooms *room)
{
  free(room->name);
  free(room);
}

void		xfree_list(t_list *list)
{
  t_rooms	*del;
  t_rooms	*tmp;

  if (list != NULL)
    {
      tmp = list->first;
      while (tmp != NULL)
	{
	  del = tmp;
	  tmp = tmp->next;
	  free_node(del);
	}
    }
  free(list);
}

t_list		*add_node_list(t_list *list, t_rooms *new_node)
{
  if (list != NULL)
    {
      new_node->next = NULL;
      if (list->last == NULL)
	{
	  new_node->prev = NULL;
	  list->first = new_node;
	  list->last = new_node;
	}
      else
	{
	  list->last->next = new_node;
	  new_node->prev = list->last;
	  list->last = new_node;
	}
      if (new_node->prev != NULL)
	new_node->nb = new_node->prev->nb + 1;
      list->lenght++;
    }
  return (list);
}
