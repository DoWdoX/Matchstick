/*
** check_line.c for check line in /home/DoWdoX/PROJECT/CPE/CPE_2016_matchstick
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Tue Feb 14 13:24:24 2017 DORIAN DEBOUT
** Last update Thu Mar  9 17:37:31 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

int	check_str(char *str)
{
  int	i;

  i = 0;
  str = cut_str(str);
  while (str[i])
    {
      if (!(str[i] >= '0' && str[i] <= '9'))
	return (84);
      i = i + 1;
    }
  return (0);
}

int	check_line(char *str, char *str2, int a, int i)
{
  if (check_str(str) == 84)
    {
      my_putstr("Error: invalid input (positive number expected)\n");
      return (84);
    }
  if ((str = cut_str(str)) == NULL)
    return (84);
  if (i == 0)
    {
      if (!(my_getnbr(str) >= 1 && my_getnbr(str) <= a))
	{
	  my_putstr("Error: this line is out of range\n");
	  return (84);
	}
    }
}

int	check_matches(char *str2, int i, int nb_max)
{
  if (check_str(str2) == 84)
    {
      my_putstr("Error: invalid input (positive number expected)\n");
      return (84);
    }
  if (i == 1)
    {
      if ((str2 = cut_str(str2)) == NULL)
	return (84);
      if (my_getnbr(str2) < 1 || my_getnbr(str2) > nb_max)
	{
	  if (my_getnbr(str2) == 0)
	    my_putstr("Error: you have to remove at least one match\n");
	  else
	    {
	      my_putstr("Error: you cannot remove more than ");
	      my_putnbr(nb_max);
	      my_putstr(" matches per turn\n");
	    }
	  return (84);
	}
    }
  return (0);
}

int	check_nbr_stick(char *str)
{
  int	i;
  int	a;

  i = 0;
  a = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '|')
	a = a + 1;
      i = i + 1;
    }
  return (a);
}
