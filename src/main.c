/*
** main.c for lemin in /home/francis/Documents/CPE/CPE_2016_Lem-In/src/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Sat Apr  1 22:45:03 2017 Francois Caicedo
** Last update Mon Apr 24 15:08:41 2017 Clément Poirier
*/

#include "lemin.h"
#include "parsing.h"
#include "algo.h"
#include "lib.h"

void		init_struct(t_data *data)
{
  data->matrix = INIT_NULL;
  data->input_len = INIT_NEG;
  data->path = INIT_NULL;
  data->avoid = INIT_NULL;
  data->nb_ants = INIT_ZERO;
  data->nb_rooms = INIT_ZERO;
  data->is_path  = INIT_ZERO;
  data->is_start = INIT_ZERO;
  data->is_end = INIT_ZERO;
  data->is_comment = INIT_ZERO;
  data->starting_room = INIT_NEG;
  data->ending_room = INIT_NEG;
  data->to_add = INIT_ZERO;
  data->len = INIT_ZERO;
}

int		main(int argc, char **argv)
{
  t_list	*list;
  t_data	data;

  if (argc > 1)
    return (my_printf(PRINT_STRING, ERROR_OUTPUT, ERROR_ARG), 84);
  if ((list = new_list()) == NULL)
    return (84);
  init_struct(&data);
  if (parser(list, &data) == -1 || start_algo(list, &data) == -1)
    return (84);
  return (0);
}
