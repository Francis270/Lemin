/*
** display_special_case.c for lemin in /home/francis/Documents/CPE/CPE_2016_Lemin/src/algo/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Tue Apr 18 15:52:04 2017 Francois Caicedo
** Last update Tue Apr 18 16:35:41 2017 Francois Caicedo
*/

#include "algo.h"
#include "lib.h"

void		display_special_case(t_list *list, t_data *data)
{
  int		i;
  int		j;

  i = INIT_NEG;
  my_printf(PRINT, 1, 1, get_name_room(list, data->path[1]));
  my_putchar(NLINE, 1);
  while (++i != data->nb_ants - (data->len - 2))
    {
      j = INIT_NEG;
      while (++j != 2)
	{
	  if (j != 0)
	    my_putchar(SPACE, 1);
	  my_printf(PRINT, 1, j + 1 + i,
		    get_name_room(list, data->path[data->len - 1 - j]));
	}
      my_putchar(NLINE, 1);
    }
  my_printf(PRINT, 1, data->nb_ants,
		  get_name_room(list, data->path[data->len - 1]));
  my_putchar(NLINE, 1);
}
