/*
** setup_matrix.c for lemin in /home/clement/projects/Epitech/C_Prog_Elem/Lem_in/CPE_2016_Lemin/src/parsing/
**
** Made by Clément Poirier
** Login   <Poirie_c@epitech.net>
**
** Started on  Tue Apr 11 11:13:58 2017 Clément Poirier
** Last update Sun Apr 16 23:07:56 2017 Francois Caicedo
*/

#include "lemin.h"
#include "parsing.h"
#include "lib.h"

void	reset_matrix(t_data *data)
{
  int	i;
  int	j;

  i = 0;
  while (i < data->nb_rooms)
    {
      j = 0;
      while (j < data->nb_rooms)
	{
	  data->matrix[i][j] = '0';
	  j++;
	}
      data->matrix[i][j] = '\0';
      i++;
    }
}

int	alloc_matrix(t_data *data)
{
  int	i;

  if ((data->matrix = malloc(sizeof(char*) * (data->nb_rooms + 1))) == NULL)
    return (-1);
  i = 0;
  while (i < data->nb_rooms)
    {
      if ((data->matrix[i] = malloc(sizeof(char) *
				    (data->nb_rooms + 1))) == NULL)
	return (-1);
      i++;
    }
  data->matrix[i] = NULL;
  reset_matrix(data);
  return (0);
}
