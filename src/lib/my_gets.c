/*
** get_next_line.c for lib in /home/francis/Documents/LIB/is_new_project/lib/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Sat Feb 18 00:51:25 2017 Francois Caicedo
** Last update Mon Apr  3 17:59:16 2017 Francois Caicedo
*/

#include "lib.h"

int		my_fd_len(const int fd)
{
  char		*tmp;
  size_t	len;

  tmp = INIT_NULL;
  len = INIT_ZERO;
  while ((tmp = get_next_line(fd, INIT_ZERO, INIT_ZERO)))
    {
      if (tmp == NULL)
	return (-1);
      free(tmp);
      len++;
    }
  return (len);
}

int		my_getnbr(const char *str)
{
  size_t	len;
  int		sign;
  int		final;

  len = final = INIT_ZERO;
  sign = INIT_ONE;
  while ((str[len] == DASH) || (str[len] == PLUS))
    {
      if (str[len] == DASH)
	sign = - sign;
      len++;
    }
  while ((str[len] >= ZERO) && (str[len] <= NINE))
    final = (final * 10 - ZERO + str[len++]);
  return (sign * final);
}

char		char_from_buffer(const int fd)
{
  static char 	*save = INIT_NULL;
  static char 	buf[READ_SIZE];
  static int  	rd = INIT_ZERO;
  static int	i = INIT_ZERO;

  if (rd == 0)
    {
      if ((rd = read(fd, buf, READ_SIZE)) <= 0)
	return (0);
      i = INIT_ZERO;
      save = (char *)buf;
    }
  rd--;
  return (save[i++]);
}

char		*get_next_line(const int fd, int lenght, int need_realloc)
{
  char 	*line;
  char	new_char;

  if ((new_char = char_from_buffer(fd)) == 0)
    return (NULL);
  if (new_char == '\0')
    return (NULL);
  if ((line = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
    return (NULL);
  while (new_char != '\n' && new_char)
    {
      line[lenght++] = new_char;
      if ((new_char = char_from_buffer(fd)) == 0)
	return (NULL);
      need_realloc++;
      if (need_realloc == (READ_SIZE - 1))
	{
	  line[lenght] = INIT_ZERO;
	  if ((line = my_realloc_1dc(line, (lenght + READ_SIZE + 1))) == NULL)
	    return (NULL);
	  need_realloc = INIT_ZERO;
	}
    }
  line[lenght] = INIT_ZERO;
  return (line);
}
