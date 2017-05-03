/*
** display.c for lemin in /home/francis/Documents/CPE/CPE_2016_Lemin/src/algo/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Sun Apr  9 11:50:41 2017 Francois Caicedo
** Last update Mon Apr 24 15:06:28 2017 Clément Poirier
*/

#include "lemin.h"
#include "algo.h"
#include "lib.h"

char		*get_name_room(t_list *list, int nb)
{
  t_rooms	*tmp;

  tmp = list->first;
  while (tmp)
    {
      if (nb == tmp->nb)
	return (tmp->name);
      tmp = tmp->next;
    }
  return (NULL);
}

void		display_last(t_list *list, t_data *data)
{
  int		i;
  int		j;
  int		len;

  i = INIT_NEG;
  len = data->len - 1;
  while ((data->len - 1) - ++i)
    {
      j = INIT_NEG;
      len--;
      while (++j != len)
	{
	  if (j != 0)
	    my_putchar(SPACE, 1);
	  my_printf(PRINT, 1, data->nb_ants - 1 + i + j,
		    get_name_room(list, data->path[data->len - 1 - j]));
	}
      if (data->nb_ants - 1 + i + j != data->nb_ants &&
	  data->path[data->len - 1 - j] != data->path[data->len - 1])
	my_putchar(NLINE, 1);
    }
}

void		display_first(t_list *list, t_data *data, int i, int j)
{
  while (++i != data->len)
    {
      j = INIT_NEG;
      while (++j != i)
	{
	  if (j != 0)
	    my_putchar(SPACE, 1);
	  my_printf(PRINT, 1, j + 1, get_name_room(list, data->path[i - j]));
	}
      if (j == i && i != 0)
	my_putchar(NLINE, 1);
    }
  i = INIT_NEG;
  while (++i != data->nb_ants - (data->len - 1))
    {
      j = INIT_NEG;
      while (++j != data->len - 1)
	{
	  if (j != 0)
	    my_putchar(SPACE, 1);
	  my_printf(PRINT, 1, j + i + 2,
		    get_name_room(list, data->path[data->len - 1 - j]));
	}
      my_putchar(NLINE, 1);
    }
}

int		display_erverything(t_list *list, t_data *data)
{
  my_putstr(MOVES, 1);
  if (data->len - 1 == 2)
    display_special_case(list, data);
  else
    {
      display_first(list, data, INIT_NEG, INIT_NEG);
      display_last(list, data);
    }
  return (0);
}
