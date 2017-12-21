/*
** main.c for Project Name in /home/buchse_a/Scripts/build
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Mon Apr 14 10:34:44 2014 Antoine Buchser
** Last update Wed Apr 30 16:12:46 2014 Thomas MORITZ
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "fourmiz.h"

void	my_perror(char *str)
{
  perror(str);
  exit(EXIT_FAILURE);
}

void	my_error(char *str)
{
  if (str)
    my_putstr(str);
  exit(EXIT_FAILURE);
}

void	free_wordtab(char **wordtab)
{
  int	i;

  i = 0;
  while (wordtab && wordtab[i])
    {
      free(wordtab[i]);
      i++;
    }
  free(wordtab);
}
