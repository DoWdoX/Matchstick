/*
** check_end.c for check end of game in /home/DoWdoX/PROJECT/CPE/CPE_2016_matchstick
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Tue Feb 14 13:01:58 2017 DORIAN DEBOUT
** Last update Wed Feb 15 15:32:32 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

int	check_end(char **tab, int k, int b)
{
  int	i;
  int	j;
  int	a;

  i = 0;
  a = 0;
  while (tab[i])
    {
      j = 0;
      while (tab[i][j])
	{
	  if (tab[i][j] == '|')
	    a = a + 1;
	  j = j + 1;
	}
      i = i + 1;
    }
  if (a != 0)
    return (0);
  if (k == 0)
    return (1);
  else if (k == 1)
    return (2);
}
