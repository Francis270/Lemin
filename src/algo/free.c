/*
** free.c for lemin in /home/francis/Documents/CPE/CPE_2016_Lemin/src/algo/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Sun Apr  9 11:53:02 2017 Francois Caicedo
** Last update Mon Apr 24 15:05:46 2017 Clément Poirier
*/

#include "lemin.h"
#include "algo.h"
#include "parsing.h"
#include "lib.h"

void		free_everything(t_list *list, t_data *data)
{
  xfree(data->path);
  xfree(data->avoid);
  my_free_2dc(data->matrix);
  xfree_list(list);
}
