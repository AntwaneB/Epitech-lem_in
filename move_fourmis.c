/*
** main.c for Project Name in /home/buchse_a/Scripts/build
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Mon Apr 14 10:34:44 2014 Antoine Buchser
** Last update Sat May  3 14:38:35 2014 Hugo Schoch
*/

#include "fourmiz.h"

int	init_cycles(t_cor *core)
{
  int	cycle_size;
  int	nb_foumis_end;
  t_res	*tmp;

  cycle_size = 0;
  nb_foumis_end = 0;
  while (core->fourmis_nb > nb_foumis_end)
    {
      tmp = core->res;
      nb_foumis_end = 0;
      cycle_size++;
      while (tmp)
	{
	  tmp->max_cycle = (cycle_size - (tmp->size - 1));
	  nb_foumis_end = nb_foumis_end + tmp->max_cycle;
	  tmp = tmp->next;
	}
    }
  return (cycle_size);
}

int	init_move_fourmis(t_cor *core)
{
  t_fmi	*tmp_fmi;
  t_res	*tmp_way;
  int	nb_moves;

  tmp_fmi = core->fourmis;
  tmp_way = core->res;
  while (tmp_way && tmp_fmi)
    {
      nb_moves = 0;
      while (nb_moves < tmp_way->max_cycle && tmp_fmi)
	{
	  tmp_fmi->start_cycle = nb_moves;
	  tmp_fmi->way = tmp_way->list;
	  tmp_fmi = tmp_fmi->next;
	  nb_moves++;
	}
      tmp_way = tmp_way->next;
    }
  return (-1);
}

int	go_to_next_room(int room, int *list)
{
  int	pos;

  pos = 0;
  while (list[pos] != room && list[pos] != -1)
    pos++;
  return ((list[pos] == -1) ? -1 : list[pos + 1]);
}

void	move_fourmis(t_cor *core)
{
  int	cycle[3];
  t_res *tmp;
  t_fmi *tmp_fmi;

  cycle[1] = init_cycles(core);
  cycle[0] = init_move_fourmis(core);
  while (cycle[0] < cycle[1] && (cycle[0]++) >= -1)
    {
      cycle[2] = 0;
      tmp_fmi = core->fourmis;
      while (tmp_fmi)
	{
	  if (tmp_fmi->start_cycle <= cycle[0] && tmp_fmi->room != -1)
	    {
	      tmp_fmi->room = go_to_next_room(tmp_fmi->room, tmp_fmi->way);
	      if (tmp_fmi->room != -1 && (cycle[2]++) > 0)
		my_printf(" P%d-%d", tmp_fmi->nb + 1, tmp_fmi->room);
	      else if (tmp_fmi->room != -1 && (cycle[2]++) >= 0)
		my_printf("P%d-%d", tmp_fmi->nb + 1, tmp_fmi->room);
	    }
	  tmp_fmi = tmp_fmi->next;
	}
      if (cycle[0] < (cycle[1] - 1))
	my_putchar('\n');
    }
}
