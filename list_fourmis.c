/*
** main.c for Project Name in /home/buchse_a/Scripts/build
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Mon Apr 14 10:34:44 2014 Antoine Buchser
** Last update Wed Apr 30 16:11:39 2014 Thomas MORITZ
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "fourmiz.h"

void	fourmi_put_in_list(t_fmi **list, int nb, int room)
{
  t_fmi	*tmp;
  t_fmi	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    my_perror("malloc() failed");
  elem->next = NULL;
  elem->nb = nb;
  elem->room = room;
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

void	fourmi_free_list(t_fmi **list)
{
  t_fmi	*rm;
  t_fmi	*tmp;

  tmp = *list;
  while (tmp)
    {
      rm = tmp;
      tmp = tmp->next;
      free(rm);
    }
  *list = NULL;
}
