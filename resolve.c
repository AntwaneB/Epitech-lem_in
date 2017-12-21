/*
** main.c for Project Name in /home/buchse_a/Scripts/build
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Mon Apr 14 10:34:44 2014 Antoine Buchser
** Last update Sat May  3 14:50:50 2014 Hugo Schoch
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "fourmiz.h"

int	add_to_list_res(t_cor *core, int *list)
{
  t_res	*tmp;
  t_res	*new;

  tmp = core->res;
  if ((new = malloc(sizeof(*new))) == NULL)
    my_perror("malloc : ");
  new->list = list;
  if (tmp == NULL)
    {
      new->next = NULL;
      core->res = new;
    }
  else
    {
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new;
      new->next = NULL;
    }
  return (1);
}

int	*my_add_list(int *list, int new_value)
{
  int	*res;
  int	size;
  int	pos;

  size = 0;
  pos = 0;
  while (list[size] != -1)
    size++;
  if ((res = malloc((size + 2) * sizeof(*res))) == NULL)
    return (NULL);
  while (pos < size)
    {
      res[pos] = list[pos];
      pos++;
    }
  res[pos] = new_value;
  pos++;
  res[pos] = -1;
  return (res);
}

int	is_good_bridge(t_bdg *bridge, int id_room, int *list_rooms)
{
  if (bridge->room1 == id_room)
    return (list_rooms[bridge->room2]);
  else if (bridge->room2 == id_room)
    return (list_rooms[bridge->room1]);
  else
    return (1);
}

void	proceed_fourmis(t_cor *core)
{
  int	*list_rooms;
  int	pos;

  get_nb_room(core);
  if ((list_rooms = malloc((core->rooms_nb + 1) * sizeof(int))) == NULL ||
      (core->sol = malloc(sizeof(core->sol))) == NULL ||
      (core->sol->list = malloc(2 * sizeof(int))) == NULL)
    my_perror("malloc : ");
  pos = 0;
  while (pos < core->rooms_nb)
    {
      list_rooms[pos] = 0;
      pos++;
    }
  list_rooms[core->rooms_nb] = -1;
  core->sol->list[0] = room_get_start(core->rooms);
  core->sol->list[1] = -1;
  core->res = NULL;
  get_ways(core, core->sol, list_rooms, room_get_start(core->rooms));
  order_lists(core);
  move_fourmis(core);
}
