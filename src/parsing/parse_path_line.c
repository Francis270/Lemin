/*
** parse_path_line.c for lemin in /home/clement/projects/Epitech/C_Prog_Elem/Lem_in/CPE_2016_Lemin/src/parsing/
**
** Made by Clément Poirier
** Login   <Poirie_c@epitech.net>
**
** Started on  Mon Apr 10 16:38:50 2017 Clément Poirier
** Last update Mon Apr 24 15:31:16 2017 Clément Poirier
*/

#include "lemin.h"
#include "parsing.h"
#include "lib.h"

int		is_comment(char *tmp)
{
  int		i;
  int		is_nb;

  i = INIT_NEG;
  is_nb = INIT_ZERO;
  if (my_strcmp(tmp, LABEL_START) == 0 ||
      my_strcmp(tmp, LABEL_END) == 0)
    return (0);
  while (tmp[++i])
    {
      if (tmp[i] >= 48 && tmp[i] <= 57)
	is_nb = INIT_ONE;
    }
  if (is_nb == 0)
    return (-1);
  i = INIT_NEG;
  while (tmp[++i])
    {
      if (tmp[i] == HASHTAG)
	tmp = my_strncpy(tmp, tmp, i - 1);
    }
  return (0);
}

int		check_error_label(t_list *list, t_rooms *room)
{
  t_rooms	*tmp;

  tmp = list->first;
  if (list != NULL)
    {
      while (tmp != NULL)
	{
	  if (room->is_start == 1)
	    {
	      if (tmp->is_start == 1)
		return (-1);
	    }
	  else if (room->is_end == 1)
	    {
	      if (tmp->is_end == 1)
		return (-1);
	    }
	  tmp = tmp->next;
	}
    }
  return (0);
}

int		check_error_line_path(char *tmp)
{
  int		i;

  i = 0;
  while (tmp[i] != DASH)
    i++;
  while (tmp[i] && tmp[i] != SPACE)
    i++;
  if (tmp[i] == SPACE)
    {
      if (tmp[i + 1] != HASHTAG)
	return (-1);
  }
  return (0);
}

int		setup_matrix_name_line_path(t_list *list, t_data *data, char *tmp)
{
  char		*n_first;
  char		*n_second;
  t_rooms	*r_first;
  t_rooms	*r_second;

  if (check_error_line_path(tmp) == -1)
    return (-1);
  if ((n_first = get_first_name_path(tmp)) == NULL)
    return (-1);
  if ((n_second = get_second_name_path(tmp)) == NULL)
    return (-1);
  if ((r_first = get_rooms_with_name(list, n_first)) == NULL)
    return (-1);
  if ((r_second = get_rooms_with_name(list, n_second)) == NULL)
    return (-1);
  if (r_first->nb != r_second->nb)
    {
      data->matrix[r_first->nb][r_second->nb] = '1';
      data->matrix[r_second->nb][r_first->nb] = '1';
    }
  return (free(n_first), free(n_second), 0);
}

int	parse_path_line(t_list *list, t_data *data, char *tmp)
{
  if (alloc_matrix(data) == -1 ||
      setup_matrix_name_line_path(list, data, tmp) == -1)
    return (-1);
  my_putstr(TUN, 1);
  if (is_comment(tmp) == 0)
    my_printf(PRINT_STRING, 1, tmp);
  while (xfree(tmp) == 0 && (tmp = get_next_line(0, 0, 0)) != NULL)
    {
      if (tmp[0] == HASHTAG)
	{
	  if (tmp[1] == HASHTAG)
	   return (-1);
	}
      else
	{
	  if (tmp_is_path(tmp) != 1)
	    return (-1);
	  if (setup_matrix_name_line_path(list, data, tmp) == -1)
	    return (-1);
	}
      if (is_comment(tmp) == 0)
	my_printf(PRINT_STRING, 1, tmp);
    }
  return (setup_first_end_struct(list, data), 0);
}
