/*
** get_name_path.c for lemin in /home/clement/projects/Epitech/C_Prog_Elem/Lem_in/CPE_2016_Lemin/src/parsing/
**
** Made by Clément Poirier
** Login   <Poirie_c@epitech.net>
**
** Started on  Tue Apr 11 11:26:32 2017 Clément Poirier
** Last update Tue Apr 18 15:32:01 2017 Francois Caicedo
*/

#include "lemin.h"
#include "parsing.h"
#include "lib.h"

char	*get_first_name_path(char *tmp)
{
  int	i;
  char	*name;

  i = 0;
  while (tmp[i] != DASH)
    i++;
  if ((name = malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  i = 0;
  while (tmp[i] != DASH)
    {
      name[i] = tmp[i];
      i++;
    }
  name[i] = '\0';
  return (name);
}

char	*get_second_name_path(char *tmp)
{
  int	i;
  int	j;
  char	*name;

  i = j = 0;
  while (tmp[i++] != DASH);
  while (tmp[i++])
    j++;
  if ((name = malloc(sizeof(char) * (j + 1))) == NULL)
    return (NULL);
  i = j = 0;
  while (tmp[i++] != DASH);
  while (tmp[i] && tmp[i] != SPACE)
    {
      name[j] = tmp[i];
      j++;
      i++;
    }
  name[j] = '\0';
  return (name);
}

void		setup_first_end_struct(t_list *list, t_data *data)
{
  t_rooms	*tmp;

  tmp = list->first;
  while (tmp != NULL)
    {
      if (tmp->is_start == 1)
	data->starting_room = tmp->nb;
      if (tmp->is_end == 1)
	data->ending_room = tmp->nb;
      tmp = tmp->next;
    }
}

t_rooms		*get_rooms_with_name(t_list *list, char *name)
{
  t_rooms	*tmp;

  tmp = list->first;
  while (tmp != NULL)
    {
      if (my_strcmp(name, tmp->name) == 0)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

int		check_error_pos(t_list *list, int x, int y)
{
  t_rooms	*tmp;

  tmp = list->first;
  while (tmp != NULL)
    {
      if (x == tmp->x && y == tmp->y)
	return (-1);
      tmp = tmp->next;
    }
  return (0);
}
