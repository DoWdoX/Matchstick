/*
** game.c for game in /home/DoWdoX/PROJECT/CPE/CPE_2016_matchstick
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Mon Feb 13 14:11:08 2017 DORIAN DEBOUT
** Last update Wed Mar  8 14:50:14 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

char	**change_tab(char **tab, char *str, char *str2)
{
  int	line;
  int	match;
  int	i;

  line = my_getnbr(str) - 1;
  match = my_getnbr(str2);
  i = my_strlen(tab[line]) - 1;
  while (i > 0 && tab[line][i] == ' ')
    i = i - 1;
  while (match != 0)
    {
      tab[line][i] = ' ';
      i = i - 1;
      match = match - 1;
    }
  return (tab);
}

char	**aff_matches(char *str, char *str2, char **tab, int a)
{
  int	i;
  int	j;

  str = cut_str(str);
  str2 = cut_str(str2);
  i = my_getnbr(str) - 1;
  j = my_getnbr(str2);
  i = check_nbr_stick(tab[i]);
  if (i < j)
    {
      my_putstr("Error: not enough matches on this line\n");
      return (NULL);
    }
  my_putstr("Player removed ");
  my_putstr(str2);
  my_putstr(" match(es) from line ");
  my_putstr(str);
  my_putchar('\n');
  tab = change_tab(tab, str, str2);
  printab(tab, a, 0);
  return (tab);
}

char	**game1(int a, char **tab, char **tmp_tab, int nb_max)
{
  char	*str;
  char	*str2;

  str = NULL;
  str2 = malloc(sizeof(char) * 32000);
  my_putstr("Line: ");
  if ((str = get_next_line(0, 0)) == NULL)
    return (NULL);
  while (check_line(str, NULL, a, 0) == 84)
    {
      my_putstr("Line: ");
      if ((str = get_next_line(0, 0)) == NULL)
	return (NULL);
    }
  my_putstr("Matches: ");
  if ((str2 = get_next_line(0, 0)) == NULL)
    return (NULL);
  if (check_matches(str2, 1, nb_max) == 84)
    game1(a, tab, tab, nb_max);
  else
    {
      if ((tab = aff_matches(str, str2, tab, a)) == NULL)
	game1(a, tmp_tab, tmp_tab, nb_max);
    }
  return (tmp_tab);
}

int	game(int a, char **tab, int nb_max)
{
  int	i;

  i = 0;
  while (check_end(tab, 1, a) == 0 && check_end(tab, 0, a) == 0)
    {
      my_putstr("Your turn:\n");
      if ((tab = game1(a, tab, tab, nb_max)) == NULL)
	return (0);
      if (check_end(tab, 1, a) != 0)
	return (2);
      tab = game2(tab, tab, a, nb_max);
      if (check_end(tab, 0, a) != 0)
	return (1);
    }
}
