/*
** my_puts.c for lib in /home/francis/Documents/new_project/src/lib/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Tue Mar 28 15:13:52 2017 Francois Caicedo
** Last update Sat Apr  1 22:46:34 2017 Francois Caicedo
*/

#include "lib.h"

int		my_putchar(const char c, unsigned int output)
{
  return (write(output, &c, 1));
}

int		my_putstr(const char *s, unsigned int output)
{
  return (write(output, s, my_strlen(s)));
}

int		my_putnbr(int nb, unsigned int output)
{
  int	pow;
  int	i;

  i = INIT_ZERO;
  if (nb < 0)
    {
      nb = -nb;
      i = i + my_putchar('-', output);
    }
  pow = INIT_ONE;
  while (pow * 10 <= nb)
    pow = pow * 10;
  while (pow > 0)
    {
      i = i + my_putchar(ZERO + (nb / pow % 10), output);
      pow = pow / 10;
    }
  return (i);
}

void		my_printf(char *str, ...)
{
  va_list	args;
  int		i;
  int		output;

  va_start(args, str);
  i = INIT_ZERO;
  output = (va_arg(args, int));
  while (str[i])
    {
      if (str[i] == '%' && str[i + 1])
	{
	  i++;
	  if (str[i] == 'c')
	    my_putchar((char)va_arg(args, int), output);
	  else if (str[i] == 's')
	    my_putstr(va_arg(args, char *), output);
	  else if (str[i] == 'd')
	    my_putnbr(va_arg(args, int), output);
	}
      else
	my_putchar(str[i], output);
      i++;
    }
  va_end(args);
}
