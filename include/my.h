/*
** my.h for my.h in /home/DoWdoX/PROJECT/CPE/CPE_2016_matchstick/include
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Mon Feb 13 10:39:38 2017 DORIAN DEBOUT
** Last update Wed Feb 22 12:19:13 2017 DORIAN DEBOUT
*/

#ifndef MY_H
#define MY_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	my_putchar(char);
int	my_getnbr(char *);
int	my_strlen(char *);
int	my_putstr(char *);
char	*get_next_line(const int, int i);
int	game(int, char **, int);
void	printab(char **, int, int);
char	*cut_str(char *);
int	check_line(char *, char *, int, int);
int	check_nbr_stick(char *);
char	**game2(char **, char **, int, int);
int	my_putnbr(int);
int	check_end(char **, int, int);
int	check_matches(char *, int, int);

#endif
