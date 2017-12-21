/*
** main.c for Project Name in /home/buchse_a/Scripts/build
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Mon Apr 14 10:34:44 2014 Antoine Buchser
** Last update Wed Apr 30 16:10:58 2014 Thomas MORITZ
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "fourmiz.h"

void	file_put_in_list(t_fil **list, char *line)
{
  t_fil	*tmp;
  t_fil	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    my_perror("malloc() failed");
  elem->next = NULL;
  elem->line = (line == NULL) ? NULL : my_strdup(line);
  if (*list == NULL)
    *list = elem;
  else
    {
      tmp = *list;
      while (tmp->next)
	tmp = tmp->next;
      tmp->next = elem;
    }
}

void	file_free_list(t_fil **list)
{
  t_fil	*rm;
  t_fil	*tmp;

  tmp = *list;
  while (tmp)
    {
      rm = tmp;
      tmp = tmp->next;
      if (rm->line != NULL)
	free(rm->line);
      free(rm);
    }
  *list = NULL;
}
