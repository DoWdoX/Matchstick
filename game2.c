/*
** game2.c for game IA in /home/DoWdoX/PROJECT/CPE/CPE_2016_matchstick
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Tue Feb 14 14:29:44 2017 DORIAN DEBOUT
** Last update Thu Mar  9 16:56:34 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

char	**change_tab_IA(char **tab, int line, int matches)
{
  int	i;

  i = my_strlen(tab[line]) - 1;
  while (i > 0 && tab[line][i] == ' ')
    i = i - 1;
  while (matches != 0)
    {
      tab[line][i] = ' ';
      i = i - 1;
      matches = matches - 1;
    }
  return (tab);
}

int	check_nbr_stick_IA(char **tab, int line)
{
  int	i;
  int	a;

  i = 0;
  a = 0;
  while (tab[line][i] != '\0')
    {
      if (tab[line][i] == '|')
	a = a + 1;
      i = i + 1;
    }
  return (a);
}

char	**aff_matches_IA(int line, int matches, char **tab, int a)
{
  int	i;

  i = check_nbr_stick_IA(tab, line - 1);
  if (i < matches)
    return (NULL);
  my_putstr("\nAI's turn...\n");
  my_putstr("AI removed ");
  my_putnbr(matches);
  my_putstr(" match(es) from line ");
  my_putnbr(line);
  my_putchar('\n');
  tab = change_tab_IA(tab, line - 1, matches);
  printab(tab, a, 0);
  my_putchar('\n');
  return (tab);
}

char	**game2(char **tmp_tab, char **tab, int a, int nb_max)
{
  int	line;
  int	matches;

  line = (rand() % a) + 1;
  while (check_nbr_stick_IA(tab, line - 1) == 0)
    line = (rand() % a) + 1;
  matches = (rand() % (nb_max)) + 1;
  while (matches > check_nbr_stick_IA(tab, line - 1))
    matches = (rand() % (nb_max - 2)) + 1;
  if ((tab = aff_matches_IA(line, matches, tab, a)) == NULL)
    game2(tmp_tab, tmp_tab, a, nb_max);
  return (tab);
}
