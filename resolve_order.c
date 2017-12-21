/*
** main.c for Project Name in /home/buchse_a/Scripts/build
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Mon Apr 14 10:34:44 2014 Antoine Buchser
** Last update Sat May  3 14:44:39 2014 Hugo Schoch
*/

#include <stdlib.h>
#include "fourmiz.h"

int	get_size_lists(t_res *start)
{
  t_res	*tmp;
  int	size;

  size = 0;
  tmp = start;
  while (tmp)
    {
      tmp->size = my_size_int_tab(tmp->list);
      tmp = tmp->next;
      size++;
    }
  return (size);
}

void	order_by_size(t_cor *core)
{
  t_res	*tmp;
  t_res	*tmp_old;
  int	*swap_list;
  int	swap_size;

  tmp = core->res;
  while (tmp->next)
    {
      tmp_old = tmp;
      tmp = tmp->next;
      if (tmp_old->size > tmp->size)
  	{
  	  swap_list = tmp_old->list;
  	  tmp_old->list = tmp->list;
  	  tmp->list = swap_list;
  	  swap_size = tmp_old->size;
  	  tmp_old->size = tmp->size;
  	  tmp->size = swap_size;
  	}
    }
}

void	optimize_ways(t_cor *core)
{
  t_res	*start;
  t_res *tmp;
  t_res	*tmp_prev;
  int	*list_rooms;

  start = core->res;
  while (start && start->next)
    {
      list_rooms = get_rooms_from_way(core, start->list);
      tmp = start;
      while (tmp && tmp->next)
	{
	  tmp_prev = tmp;
	  tmp = tmp->next;
	  if (is_common_room(list_rooms, tmp->list))
	    {
	      tmp_prev->next = tmp->next;
	      tmp = tmp_prev;
	    }
	}
      start = start->next;
    }
}

void	order_lists(t_cor *core)
{
  int	nb;
  int	size;

  size = get_size_lists(core->res);
  nb = 1;
  while (size)
    {
      order_by_size(core);
      size--;
    }
  optimize_ways(core);
}
