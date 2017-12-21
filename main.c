/*
** main.c for Project Name in /home/buchse_a/Scripts/build
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Mon Apr 14 10:34:44 2014 Antoine Buchser
** Last update Tue Apr 22 14:09:22 2014 
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "fourmiz.h"

static void	free_everything(t_cor *core)
{
  file_free_list(&(core->file));
  room_free_list(&(core->rooms));
  fourmi_free_list(&(core->fourmis));
  bridge_free_list(&(core->bridges));
}

static void	init_core(t_cor *core)
{
  core->file = NULL;
  core->rooms = NULL;
  core->fourmis = NULL;
  core->bridges = NULL;
  core->fourmis_nb = -1;
  read_file(core);
}

/*
void		proceed_fourmis(t_cor *core)
{
  t_room	*room;
  t_bdg		*bdg;

  my_printf("Nombre de fourmis : %d\n", core->fourmis_nb);
  room = core->rooms;
  while (room)
    {
      my_printf("%s(%d): %d-%d ==> %d/%d\n", room->name, room->id,
		room->x, room->y, room->start, room->end);
      room = room->next;
    }
  my_putchar(10);
  bdg = core->bridges;
  while (bdg)
    {
      my_printf("%s --- %s\n",
		room_get_name(core->rooms, bdg->room1),
		room_get_name(core->rooms, bdg->room2));
      bdg = bdg->next;
    }
}
*/

/* void		proceed_fourmis(t_cor *core) */
/* { */
/*   (void)core; */
/* } */

int	main(void)
{
  t_cor	core;

  init_core(&core);
  validate_everything(&core);
  parse_everything(&core);
  proceed_fourmis(&core);
  free_everything(&core);
  return (EXIT_SUCCESS);
}
