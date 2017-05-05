/*
** get_next_line.c for line.c in /home/DoWdoX/PROJECT/CPE/get
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Mon Jan  9 16:20:34 2017 DORIAN DEBOUT
** Last update Thu Feb 23 17:48:27 2017 DORIAN DEBOUT
*/

#include "./include/get_next_line.h"
#include "./include/my.h"

char	*my_strncat(char *dest, char *src, int nb)
{
  int	i;
  int	j;

  i = 0;
  while (dest[i] != '\0')
    i = i + 1;
  j = 0;
  while (src[j] != '\0' && j < nb)
    {
      dest[i] = src[j];
      i = i + 1;
      j = j + 1;
    }
  dest[i] = '\0';
  return (dest);
}

int	count(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '\0' || str[i] == '\n')
	return (1);
      i = i + 1;
    }
  return (0);
}

int	get_idx(char *buff)
{
  int	i;

  i = 1;
  while (i != READ_SIZE)
    {
      if (buff[i] == '\0' || buff[i] == '\n')
	return (i);
      else
	i = i + 1;
    }
  return (i);
}

char		*get_next_line(const int fd, int i)
{
  char		*buff;
  char		*line;

  buff = malloc(sizeof(char) * (32000));
  line = malloc(sizeof(char) * (32000));
  if (read(fd, buff, READ_SIZE) == 0)
    return (NULL);
  while (count(buff) == 0)
    {
      line = my_strncat(line, buff, my_strlen(buff));
      if (read(fd, buff, READ_SIZE) == 0)
	return (NULL);
      i = i + 1;
    }
  if (buff[i] == '\0' || buff[i] == '\n')
    {
      i = get_idx(buff);
      line = my_strncat(line, buff, i - 1);
      return (line);
    }
  return (NULL);
}
