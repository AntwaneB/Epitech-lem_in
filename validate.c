/*
** main.c for Project Name in /home/buchse_a/Scripts/build
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Mon Apr 14 10:34:44 2014 Antoine Buchser
** Last update Wed Apr 30 16:13:38 2014 Thomas MORITZ
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "fourmiz.h"

static void	validate_fourmis(t_fil **tmp)
{
  if (!(*tmp) || !((*tmp)->line) || get_line_type((*tmp)->line) != FOURMIS_NB)
    my_error("Invalid file, missing fourmis number, exiting.\n");
  *tmp = (*tmp)->next;
}

static void	validate_rooms(t_fil **tmp)
{
  int		soe;

  soe = 0;
  while ((*tmp) && (*tmp)->line
	 && (get_line_type((*tmp)->line) == ROOM
	     || get_line_type((*tmp)->line) == START
	     || get_line_type((*tmp)->line) == END))
    {
      if ((get_line_type((*tmp)->line) == START && (soe & 0x01 || soe & 0x04))
	  || (get_line_type((*tmp)->line) == END
	      && (soe & 0x02 || soe & 0x08)))
	my_error("More than one definition of start or end, exiting.\n");
      if (soe & 0x01)
	soe |= 0x04;
      if (soe & 0x02)
	soe |= 0x08;
      if (get_line_type((*tmp)->line) == START)
	soe |= 0x01;
      else if (get_line_type((*tmp)->line) == END)
	soe |= 0x02;
      *tmp = (*tmp)->next;
    }
  if ((soe & 0x01 && !(soe & 0x04))
      || (soe & 0x02 && !(soe & 0x08)))
    my_error("Missing room after definition of start or end, exiting.\n");
}

static void	validate_bridges(t_fil **tmp)
{
  while ((*tmp))
    {
      if (!((*tmp)->line) || get_line_type((*tmp)->line) != BRIDGE)
	my_error("Invalid file structure, exiting.\n");
      else
	*tmp = (*tmp)->next;
    }
}

void	validate_everything(t_cor *core)
{
  t_fil	*tmp;

  tmp = core->file;
  validate_fourmis(&tmp);
  validate_rooms(&tmp);
  validate_bridges(&tmp);
}
