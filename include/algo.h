/*
** lemin.h for lemin in /home/francis/Documents/CPE/CPE_2016_Lem-In/include/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Sat Apr  1 22:44:38 2017 Francois Caicedo
** Last update Mon Apr 24 14:54:33 2017 Clément Poirier
*/

#ifndef ALGO_H_
# define ALGO_H_

#define PRINT ("P%d-%s")

#include "parsing.h"

int		start_algo(t_list *, t_data *);
int		backtrack(t_data *, int);
int		find_shortest_path(t_data *, int, int, int);
int		check(t_data *, int, int);
char		*get_name_room(t_list *, int);
int		display_erverything(t_list *, t_data *);
void		display_input_file(t_list *, t_data *);
void		display_special_case(t_list *, t_data *);
void		free_everything(t_list *, t_data *);
void		xfree_list(t_list *);

#endif /* !ALGO_H_ */
