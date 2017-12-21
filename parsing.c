/*
** main.c for Project Name in /home/buchse_a/Scripts/build
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Mon Apr 14 10:34:44 2014 Antoine Buchser
** Last update Wed Apr 30 16:12:58 2014 Thomas MORITZ
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "fourmiz.h"

void	read_file(t_cor *core)
{
  char	*line;

  while ((line = get_next_line(0)) != NULL)
    {
      file_put_in_list(&(core->file), line);
      free(line);
    }
}

static void	read_rooms(t_cor *core)
{
  t_fil		*tmp;
  char		**wordtab;
  t_pos		pos;
  int		eos;

  tmp = core->file;
  while (tmp)
    {
      if (tmp->line && (get_line_type(tmp->line) == ROOM
			|| get_line_type(tmp->line) == START
			|| get_line_type(tmp->line) == END))
	{
	  eos = 0;
	  eos = (get_line_type(tmp->line) == START) ? 1 : eos;
	  eos = (get_line_type(tmp->line) == END) ? -1 : eos;
	  wordtab = my_str_to_wordtab((!eos) ? tmp->line : tmp->next->line);
	  pos.x = my_getnbr(wordtab[1]);
	  pos.y = my_getnbr(wordtab[2]);
	  room_put_in_list(&(core->rooms), wordtab[0], &pos, eos);
	  tmp = (eos) ? tmp->next : tmp;
	  free_wordtab(wordtab);
	}
      tmp = (tmp != NULL) ? tmp->next : tmp;
    }
}

static void	read_fourmis(t_cor *core)
{
  t_fil		*tmp;
  int		i;

  tmp = core->file;
  if (tmp && tmp->line && get_line_type(tmp->line) == FOURMIS_NB)
    {
      core->fourmis_nb = my_getnbr(tmp->line);
      i = 0;
      while (i < core->fourmis_nb)
	{
	  fourmi_put_in_list(&(core->fourmis), i,
			     room_get_start(core->rooms));
	  i++;
	}
    }
  else
    my_error("Invalid file, missing fourmis number, exiting.\n");
}

static void	read_bridges(t_cor *core)
{
  t_fil		*tmp;
  int		i;

  tmp = core->file;
  while (tmp)
    {
      if (tmp->line && get_line_type(tmp->line) == BRIDGE)
	{
	  i = -1;
	  while (tmp->line && tmp->line[++i] != '-');
	  tmp->line[i] = '\0';
	  if (room_get_id(core->rooms, tmp->line)
	      != room_get_id(core->rooms, tmp->line + i + 1))
	    {
	      bridge_put_in_list(&(core->bridges),
				 room_get_id(core->rooms, tmp->line),
				 room_get_id(core->rooms, tmp->line + i + 1));
	    }
	  tmp->line[i] = '-';
	}
      tmp = tmp->next;
    }
}

void	parse_everything(t_cor *core)
{
  read_file(core);
  read_rooms(core);
  read_bridges(core);
  read_fourmis(core);
}
