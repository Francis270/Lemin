/*
** parse_core.c for lem_in in /home/clement/projects/Epitech/C_Prog_Elem/Lem_in/CPE_2016_Lemin/src/parsing/
**
** Made by Clément Poirier
** Login   <Poirie_c@epitech.net>
**
** Started on  Fri Apr  7 15:55:17 2017 Clément Poirier
** Last update Mon Apr 24 15:27:42 2017 Clément Poirier
*/

#include "lib.h"
#include "parsing.h"
#include "lemin.h"

char	*get_name(char *tmp)
{
  char	*name;
  int	i;

  i = 0;
  while (tmp[i] != SPACE && tmp[i])
    i++;
  if ((name = malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  i = 0;
  while (tmp[i] != SPACE && tmp[i])
    {
      name[i] = tmp[i];
      i++;
    }
  name[i] = '\0';
  return (name);
}

int	count_space(char *tmp)
{
  int	i;
  int	count;

  i = -1;
  count = 0;
  while (tmp[++i])
    {
      if (tmp[i] == SPACE)
	count++;
    }
  return (count);
}

int	parse_room_pos(t_data *data, t_rooms *room, char *tmp)
{
  int	size_1;
  int	size_2;
  int	size_3;

  size_1 = my_strlen(room->name);
  if (tmp[size_1] != SPACE)
    return (-1);
  room->x = my_getnbr(&tmp[size_1 + 1]);
  size_2 = size_of_nb(room->x);
  if (tmp[size_1 + size_2 + 1] != SPACE)
    return (-1);
  room->y = my_getnbr(&tmp[size_1 + size_2 + 2]);
  size_3 = size_of_nb(room->y);
  if (tmp[size_1 + size_2 + size_3 + 2] == SPACE)
    {
      if (tmp[size_1 + size_2 + size_3 + 3] != HASHTAG)
	return (-1);
    }
  else
    {
      if (my_strlen(tmp) != size_1 + size_2 + size_3 + 2)
	return (-1);
    }
  return (0);
}

t_rooms		*init_rooms_struct(t_rooms *room)
{
  if ((room = malloc(sizeof *room)) == NULL)
    return (NULL);
  room->name = NULL;
  room->nb = 0;
  room->is_start = 0;
  room->is_end = 0;
  room->x = 0;
  room->y = 0;
  room->next = NULL;
  room->prev = NULL;
  return (room);
}

int		parse_rooms_line(t_list *list, t_data *data, char *tmp)
{
  t_rooms	*room;

  room = NULL;
  if ((room = init_rooms_struct(room)) == NULL)
    return (-1);
  if (data->is_start == 1)
    room->is_start = 1;
  else if (data->is_end == 1)
    room->is_end = 1;
  room->name = get_name(tmp);
  if (parse_room_pos(data, room, tmp) == -1)
    return (-1);
  if (check_error_pos(list, room->x, room->y) == -1)
    return (-1);
  if (check_error_label(list, room) == -1)
    return (-1);
  if (room->is_start == 1)
      my_printf("%s\n", 1, LABEL_START);
  else if (room->is_end == 1)
    my_printf("%s\n", 1, LABEL_END);
  my_printf("%s %d %d\n", 1, room->name, room->x, room->y);
  add_node_list(list, room);
  return (0);
}
