/*
** main.c for Project Name in /home/buchse_a/Scripts/build
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Mon Apr 14 10:34:44 2014 Antoine Buchser
** Last update Sat May  3 14:43:58 2014 Hugo Schoch
*/

#include <stdlib.h>
#include "fourmiz.h"

int	my_size_int_tab(int *tab)
{
  int	pos;

  pos = 0;
  while (tab[pos] != -1)
    pos++;
  return (pos);
}

int	*get_rooms_from_way(t_cor *core, int *list)
{
  int	pos;
  int	*list_rooms;

  if ((list_rooms = malloc((core->rooms_nb + 1) * sizeof(int))) == NULL)
    my_perror("malloc : ");
  pos = 0;
  while (pos < core->rooms_nb)
    {
      list_rooms[pos] = 0;
      pos++;
    }
  list_rooms[pos] = -1;
  pos = 1;
  while (list[pos] != -1 && list[pos + 1] != -1)
    {
      list_rooms[list[pos]] = 1;
      pos++;
    }
  return (list_rooms);
}

int	is_common_room(int *list1, int *list2)
{
  int	pos;

  pos = 0;
  while (list2[pos] != -1)
    {
      if (list1[list2[pos]] == 1)
	return (1);
      else
	pos++;
    }
  return (0);
}
