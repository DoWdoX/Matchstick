/*
** functions2.c for functions basics 2 in /home/DoWdoX/PROJECT/CPE/CPE_2016_matchstick
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Tue Feb 14 15:09:07 2017 DORIAN DEBOUT
** Last update Tue Feb 14 15:10:03 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

int		my_putnbr(int nb)
{
  long int	i;

  i = nb;
  if (i < 0)
    {
      my_putchar('-');
      i = i * -1;
    }
  if (i >= 10)
    my_putnbr(i / 10);
  i = i % 10 + '0';
  my_putchar(i);
}
