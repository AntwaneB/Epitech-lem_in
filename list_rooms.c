/*
** main.c for Project Name in /home/buchse_a/Scripts/build
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Mon Apr 14 10:34:44 2014 Antoine Buchser
** Last update Wed Apr 30 16:11:51 2014 Thomas MORITZ
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "fourmiz.h"

void		room_put_in_list(t_room **list, char *name,
				 t_pos *pos, int startorend)
{
  static int	id = 0;
  t_room	*tmp;
  t_room	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    my_perror("malloc() failed");
  elem->next = NULL;
  elem->id = id;
  elem->name = my_strdup(name);
  elem->x = pos->x;
  elem->y = pos->y;
  elem->start = (startorend == 1) ? 1 : 0;
  elem->end = (startorend == -1) ? 1 : 0;
  elem->fourmis = 0;
  if (*list == NULL)
    *list = elem;
  else
    {
      tmp = *list;
      while (tmp->next)
	tmp = tmp->next;
      tmp->next = elem;
    }
  id++;
}

void		room_free_list(t_room **list)
{
  t_room	*rm;
  t_room	*tmp;

  tmp = *list;
  while (tmp)
    {
      rm = tmp;
      tmp = tmp->next;
      if (rm->name != NULL)
	free(rm->name);
      free(rm);
    }
  *list = NULL;
}

int		room_get_id(t_room *list, char *name)
{
  t_room	*tmp;
  int		id;

  id = -1;
  tmp = list;
  while (tmp && id == -1)
    {
      if (!my_strcmp(tmp->name, name))
	id = tmp->id;
      else
	tmp = tmp->next;
    }
  return (id);
}

char		*room_get_name(t_room *list, int id)
{
  t_room	*tmp;
  int		found;

  found = 0;
  tmp = list;
  while (tmp && !found)
    {
      if (tmp->id == id)
	found = 1;
      else
	tmp = tmp->next;
    }
  return ((found == 1) ? tmp->name : NULL);
}

int		room_get_start(t_room *list)
{
  t_room	*tmp;
  int		found;

  found = 0;
  tmp = list;
  while (tmp && !found)
    {
      if (tmp->start)
	found = 1;
      else
	tmp = tmp->next;
    }
  return ((found == 1) ? tmp->id : -1);
}

int		room_get_end(t_room *list)
{
  t_room	*tmp;
  int		found;

  found = 0;
  tmp = list;
  while (tmp && !found)
    {
      if (tmp->end)
	found = 1;
      else
	tmp = tmp->next;
    }
  return ((found == 1) ? tmp->id : -1);
}
