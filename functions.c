/*
** functions.c for functions.c in /home/DoWdoX/PROJECT/CPE/CPE_2016_matchstick
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Mon Feb 13 10:40:34 2017 DORIAN DEBOUT
** Last update Sat Feb 18 13:35:22 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0')
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i = i + 1;
    }
  return (s1[i] - s2[i]);
}

int		my_getnbr(char *str)
{
  long int	integer;
  int		i;
  int		sign;

  sign = 1;
  i = 0;
  integer = 0;
  if (my_strcmp(str, "-2147483648") == 0)
    return (-2147483648);
  while (str[i] == ' ' || str[i] == '\f' || str[i] == '\t'
	   || str[i] == '\n' || str[i] == '\r' || str[i] == '\v'
	 || str[i] == '+' || str[i] == '-')
    {
      if (str[i] == '-')
	sign = sign * - 1;
      i = i + 1;
    }
  while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
    {
      integer = integer * 10 + (str[i] - '0');
      i = i + 1;
    }
  if (integer < -2147483648 || integer > 2147483647)
    return (0);
  return (integer * sign);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i = i + 1;
  return (i);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
