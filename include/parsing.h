/*
** lemin.h for lemin in /home/francis/Documents/CPE/CPE_2016_Lem-In/include/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Sat Apr  1 22:44:38 2017 Francois Caicedo
** Last update Mon Apr 24 15:30:57 2017 Clément Poirier
*/

#ifndef PARSING_H_
# define PARSING_H_

#include "lemin.h"

#define LABEL_START "##start"
#define LABEL_END "##end"
#define NB_ANTS ("#number_of_ants\n")
#define ROOMS ("#rooms\n")
#define TUN ("#tunnels\n")
#define MOVES ("#moves\n")

typedef struct		s_rooms
{
  char			*name;
  int			nb;
  int			is_start;
  int			is_end;
  int			x;
  int			y;
  struct s_rooms	*next;
  struct s_rooms	*prev;
}			t_rooms;

typedef struct	s_list
{
  int		lenght;
  t_rooms	*first;
  t_rooms	*last;
}		t_list;

int		parser(t_list *, t_data *);
int		parse_rooms_line(t_list *, t_data *, char *);
int		parse_path_line(t_list *, t_data *, char *);
t_list		*add_node_list(t_list *, t_rooms *);
t_list		*new_list();
int		tmp_is_path(char *);
int		alloc_matrix(t_data *data);
char		*get_first_name_path(char *);
char		*get_second_name_path(char *tmp);
t_rooms		*get_rooms_with_name(t_list *, char *);
void		setup_first_end_struct(t_list *, t_data *);
int		check_error_pos(t_list *, int, int);
int		check_error_label(t_list *, t_rooms *);
int		is_comment(char *);

#endif /* !PARSING_H_ */
