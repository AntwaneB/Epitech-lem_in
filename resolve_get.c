/*
** main.c for Project Name in /home/buchse_a/Scripts/build
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Mon Apr 14 10:34:44 2014 Antoine Buchser
** Last update Sat May  3 14:50:09 2014 Hugo Schoch
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "fourmiz.h"

int	*my_cpy_list(int *list)
{
  int	size;
  int	*res;
  int	pos;

  pos = 0;
  size = 0;
  while (list[size] != -1)
    size++;
  size++;
  if ((res = malloc(size * sizeof(*res))) == NULL)
    my_perror("malloc : ");
  while (pos < size)
    {
      res[pos] = list[pos];
      pos++;
    }
  return (res);
}

void		get_nb_room(t_cor *core)
{
  int		size;
  t_room	*tmp;

  size = 0;
  tmp = core->rooms;
  while (tmp)
    {
      size++;
      tmp = tmp->next;
    }
  core->rooms_nb = size;
}

t_sol	**get_nb_bridges(t_cor *core, int id_room)
{
  t_sol	**tab;
  t_bdg	*tmp;
  int	res;
  int	pos;

  res = 0;
  pos = 0;
  tmp = core->bridges;
  while (tmp)
    {
      if ((tmp->room1 == id_room || tmp->room2 == id_room) &&
	  tmp->room1 != tmp->room2)
	res++;
      tmp = tmp->next;
    }
  if ((tab = malloc((res + 1) * sizeof(*tab))) == NULL)
    return (NULL);
  while (pos < res)
    {
      if ((tab[pos] = malloc(sizeof(**tab))) == NULL)
	return (NULL);
      pos++;
    }
  tab[res] = NULL;
  return (tab);
}

int	get_ways(t_cor *core, t_sol *res, int *list_rooms, int id_room)
{
  int	pos;
  int	nxt_room;
  t_bdg	*tmp;

  pos = 0;
  list_rooms[id_room] = 1;
  res->next = get_nb_bridges(core, id_room);
  tmp = core->bridges;
  while (res->next[pos] != NULL && tmp != NULL)
    {
      while (tmp != NULL && is_good_bridge(tmp, id_room, list_rooms))
	tmp = tmp->next;
      if (tmp != NULL)
	{
	  nxt_room = ((id_room == tmp->room1) ? tmp->room2 : tmp->room1);
	  res->next[pos]->list = my_add_list(res->list, nxt_room);
	  if (nxt_room == room_get_end(core->rooms))
	    return (add_to_list_res(core, res->next[pos]->list));
	      get_ways(core, res->next[pos], my_cpy_list(list_rooms), nxt_room);
	  tmp = tmp->next;
	}
      pos++;
    }
  return (1);
}
