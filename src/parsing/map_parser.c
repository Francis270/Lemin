/*
** map_parser.c for lemin in /home/francis/Documents/CPE/CPE_2016_Lemin/src/parsing/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Mon Apr  3 23:37:04 2017 Francois Caicedo
** Last update Sat Apr 29 23:46:14 2017 Francois Caicedo
*/

#include "lemin.h"
#include "parsing.h"
#include "lib.h"

int	tmp_is_path(char *tmp)
{
  int	i;
  int	j;

  i = -1;
  j = 0;
  while (tmp[++i])
    {
      if (tmp[i] == '-')
	j++;
    }
  return (j);
}

int	tmp_is_comment(t_data *data, char *tmp)
{
  data->is_comment = 1;
  if (my_strcmp(tmp, LABEL_START) == 0)
    {
      if (data->is_start != 0 || data->is_end != 0)
	return (-1);
      data->is_start = 1;
    }
  else if (my_strcmp(tmp, LABEL_END) == 0)
    {
      if (data->is_start != 0 || data->is_end != 0)
	return (-1);
      data->is_end = 1;
    }
  return (0);
}

int	parse_first_line(t_data *data)
{
  char	*tmp;

  if ((tmp = get_next_line(0, 0, 0)) == NULL)
    return (-1);
  if (my_strisnum(tmp) == -1)
    return (free(tmp), -1);
  if ((data->nb_ants = my_getnbr(tmp)) < 1)
    return (-1);
  xfree(tmp);
  return (0);
}

int	parser_rooms_order(t_list *list, t_data *data, char *tmp)
{
  if (tmp_is_path(tmp) == 1)
    {
      data->is_path = 1;
      data->is_comment = 0;
      if (data->nb_rooms < 2 || data->is_start == 1 || data->is_end == 1)
	return (-1);
    }
  else if (tmp[0] == HASHTAG)
    {
      if (tmp_is_comment(data, tmp) == -1)
	return (-1);
      free(tmp);
    }
  else
    {
      data->is_comment = 0;
      if (parse_rooms_line(list, data, tmp) == -1)
	return (-1);
      data->nb_rooms++;
      free(tmp);
    }
  return (0);
}

int	parser(t_list *list, t_data *data)
{
  char	*tmp;

  if (parse_first_line(data) == -1)
    return (-1);
  my_printf("%s%d\n%s", 1, NB_ANTS, data->nb_ants, ROOMS);
  while (data->is_path != 1)
    {
      if ((tmp = get_next_line(0, 0, 0)) == NULL)
	return (-1);
      if (data->is_comment == 0)
	{
	  data->is_start = 0;
	  data->is_end = 0;
	}
      if (my_strlen(tmp) < 3)
	return (-1);
      if (parser_rooms_order(list, data, tmp) == -1)
	return (-1);
    }
  if (parse_path_line(list, data, tmp) == -1)
    return (-1);
  if (data->starting_room == -1 || data->ending_room == -1)
    return (-1);
  return (0);
}
