/*
** start.c for lemin in /home/francis/Documents/CPE/CPE_2016_Lemin/src/algo/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Mon Apr  3 23:45:12 2017 Francois Caicedo
** Last update Sun Apr 30 19:27:30 2017 Francois Caicedo
*/

#include "lemin.h"
#include "algo.h"
#include "parsing.h"
#include "lib.h"

int		final_check(t_data *data, int check)
{
  int		i;

  i = INIT_NEG;
  while (data->matrix[check][++i])
    {
      if (data->matrix[check][i] == '1' && i == data->ending_room)
	return (i);
    }
  return (0);
}

int		check(t_data *data, int check, int choose)
{
  int		i;

  i = INIT_NEG;
  if (choose == 1)
    {
      while (data->path[++i] != -1)
	{
	  if (data->path[i] == check)
	    return (-1);
	}
    }
  else if (choose == 2)
    {
      while (data->avoid[++i] != -1)
	{
	  if (data->avoid[i] == check)
	    return (-1);
	}
    }
  return (0);
}

int		find_shortest_path(t_data *data, int point, int len, int i)
{
  while (1)
    {
      data->to_add = INIT_ZERO;
      if (len > data->nb_rooms)
	return (point);
      if ((data->path = my_realloc_1di(data->path, ++len + M_ALLOC)) == NULL)
	return (-1);
      data->path[len] = point;
      data->path[len + 1] = INIT_NEG;
      if ((data->to_add = final_check(data, point)) != 0)
	return (data->len = len, 0);
      i = INIT_NEG;
      while (data->matrix[point][++i])
	{
	  if (data->matrix[point][i] == '1' && check(data, i, 1) == 0 &&
	      check(data, i, 2) == 0)
	    {
	      point = i;
	      break;
	    }
	}
    }
  return (0);
}

int		backtrack(t_data *data, int ret)
{
  int		len;
  int		point;

  len = INIT_NEG;
  point = data->starting_room;
  if ((data->avoid = xmalloc(sizeof(int) * M_ALLOC)) == NULL)
    return (-1);
  data->avoid[++len] = INIT_NEG;
  data->avoid[++len] = INIT_NEG;
  len = INIT_NEG;
  while (ret != 0 || ret != -1)
    {
      ret = find_shortest_path(data, point, INIT_NEG, INIT_NEG);
      if (ret == 0 || ret == -1)
	return (ret);
      if ((data->avoid = my_realloc_1di(data->avoid, ++len + M_ALLOC)) == NULL)
	return (-1);
      data->avoid[len] = ret;
      data->avoid[len + 1] = INIT_NEG;
      if (len > data->nb_rooms)
	return (-1);
    }
  return (0);
}

int		start_algo(t_list *list, t_data *data)
{
  if (backtrack(data, INIT_ONE) == -1)
    return (-1);
  if ((data->path = my_realloc_1di(data->path, ++data->len + 2)) == NULL)
    return (-1);
  data->path[data->len] = data->to_add;
  data->path[++data->len] = INIT_NEG;
  display_erverything(list, data);
  free_everything(list, data);
  return (0);
}
