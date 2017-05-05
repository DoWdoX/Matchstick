/*
** cut_str.c for cut in /home/DoWdoX/PROJECT/CPE/CPE_2016_matchstick
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Tue Feb 14 11:13:59 2017 DORIAN DEBOUT
** Last update Wed Feb 22 15:42:36 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

char	*cut_str(char *s)
{
  int	i;
  int	j;
  int	k;
  char	*s2;

  i = 0;
  k = 0;
  j = my_strlen(s);
  s2 = malloc(sizeof(char) * (j + 1));
  while (s[i] && (s[i] == ' ' || s[i] == '\t'))
    i = i + 1;
  while (j > 2 && (s[j] == ' ' || s[j] == '\t' || s[j] == '\0'))
    j = j - 1;
  j = j + 1;
  while (i < j)
    {
      s2[k] = s[i];
      i = i + 1;
      k = k + 1;
    }
  s2[k + 1] = '\0';
  if (my_strlen(s2) > 2)
    return (NULL);
  return (s2);
}
