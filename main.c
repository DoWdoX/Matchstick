/*
** main.c for main.c in /home/DoWdoX/PROJECT/CPE/CPE_2016_matchstick
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Mon Feb 13 10:38:36 2017 DORIAN DEBOUT
** Last update Wed Feb 22 15:23:41 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

void	printab(char **tab, int a, int k)
{
  int	i;
  int	j;
  char	*str;

  str = malloc(sizeof(char) * (a * 2 + 4));
  i = 0;
  while (k < (a * 2 + 1))
    {
      str[k] = '*';
      k = k + 1;
    }
  str[k] = '\0';
  my_putstr(str);
  my_putchar('\n');
  while (tab[i])
    {
      my_putstr("*");
      my_putstr(tab[i]);
      my_putstr("*");
      my_putchar('\n');
      i = i + 1;
    }
  my_putstr(str);
  my_putstr("\n");
}

char	value_c(int j, int k, int l)
{
  char	c;

  if (j < k || j >= l)
    c = ' ';
  else
    c = '|';
  return (c);
}

char	**complete_tab(char **tab, int a, int j, int m)
{
  int	i;
  int	l;
  char	c;
  int	k;

  l = a * 2 - 1;
  m = l;
  i = a - 1;
  k = 0;
  while (i >= 0)
    {
      j = 0;
      tab[i] = malloc(sizeof(char) * (a * 2 + 4));
      while (j != m)
	{
	  c = value_c(j, k, l);
	  tab[i][j] = c;
	  j = j + 1;
	}
      tab[i][my_strlen(tab[i])] = '\0';
      l = l - 1;
      k = k + 1;
      i = i - 1;
    }
  return (tab);
}

char	**generate_map(int a, char **tab)
{
  int	i;
  int	j;

  i = 0;
  tab = malloc(sizeof(char *) * (a + 2));
  tab = complete_tab(tab, a, 0, 0);
  printab(tab, a, 0);
  my_putchar('\n');
  return (tab);
}

int	main(int ac, char **av)
{
  char	**tab;
  int	i;

  if (ac == 3)
    {
      if (my_getnbr(av[1]) < 1 || my_getnbr(av[1]) > 100
	  || my_getnbr(av[2]) < 1)
	return (84);
      tab = generate_map(my_getnbr(av[1]), tab);
      i = game(my_getnbr(av[1]), tab, my_getnbr(av[2]));
      if (i == 1)
	{
	  my_putstr("I lost... snif... but I'll get you next time!!\n");
	  return (1);
	}
      else if (i == 2)
	{
	  my_putstr("You lost, too bad...\n");
	  return (2);
	}
      else if (i == 0)
	my_putchar('\n');
      return (0);
    }
  return (84);
}
