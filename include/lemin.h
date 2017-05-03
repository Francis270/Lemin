/*
** lemin.h for lemin in /home/francis/Documents/CPE/CPE_2016_Lem-In/include/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Sat Apr  1 22:44:38 2017 Francois Caicedo
** Last update Mon Apr 24 15:08:32 2017 Clément Poirier
*/

#ifndef LEMIN_H_
# define LEMIN_H_

#define PRINT_STRING ("%s\n")
#define STANDARD_OUTPUT (1)
#define ERROR_OUTPUT (2)
#define ERROR_ARG ("Usage \t : ./lem_in < map")
#define M_ALLOC (2)

typedef	struct	s_data
{
  char		**matrix;
  int		input_len;
  int		*path;
  int		*avoid;
  int		to_add;
  int		len;
  int		nb_ants;
  int		nb_rooms;
  int		is_path;
  int		is_start;
  int		is_end;
  int		is_comment;
  int		starting_room;
  int		ending_room;
}		t_data;

#endif /* !LEMIN_H_ */
