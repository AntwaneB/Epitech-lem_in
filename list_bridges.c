/*
** main.c for Project Name in /home/buchse_a/Scripts/build
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Mon Apr 14 10:34:44 2014 Antoine Buchser
** Last update Wed Apr 30 16:10:16 2014 Thomas MORITZ
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "fourmiz.h"

static int	bridge_exists(t_bdg *list, int room1, int room2)
{
  t_bdg		*tmp;
  int		found;

  found = 0;
  tmp = list;
  while (tmp && !found)
    {
      if (tmp->room1 == room1 && tmp->room2 == room2)
	found = 1;
      else
	tmp = tmp->next;
    }
  return (found);
}

void		bridge_put_in_list(t_bdg **list, int room1, int room2)
{
  t_bdg	*tmp;
  t_bdg	*elem;

  if (!bridge_exists(*list, room1, room2))
    {
      if ((elem = malloc(sizeof(*elem))) == NULL)
	my_perror("malloc() failed");
      elem->next = NULL;
      elem->room1 = room1;
      elem->room2 = room2;
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
}

void	bridge_free_list(t_bdg **list)
{
  t_bdg	*rm;
  t_bdg	*tmp;

  tmp = *list;
  while (tmp)
    {
      rm = tmp;
      tmp = tmp->next;
      free(rm);
    }
  *list = NULL;
}
