/*
** fourmiz.h for Lem-In in /home/buchse_a/Documents/lem_in
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Mon Apr 14 13:53:31 2014 Antoine Buchser
** Last update Sat May  3 14:40:57 2014 Hugo Schoch
*/

#ifndef FOURMIZ_H_
# define FOURMIZ_H_

# define FOURMIS_NB	0
# define COMMENT	1
# define ROOM		2
# define BRIDGE		3
# define START		4
# define END		5

typedef struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

typedef struct	s_fmi
{
  int		nb;
  int		room;
  int		start_cycle;
  int		*way;
  struct s_fmi	*next;
}		t_fmi;

typedef struct	s_room
{
  int		id;
  char		*name;
  int		x;
  int		y;
  int		start;
  int		end;
  int		fourmis;
  struct s_room	*next;
}		t_room;

typedef struct	s_fil
{
  char		*line;
  struct s_fil	*next;
}		t_fil;

typedef struct	s_bdg
{
  int		room1;
  int		room2;
  struct s_bdg	*next;
}		t_bdg;

typedef struct	s_sol
{
  int		*list;
  int		length;
  struct s_sol	**next;
}		t_sol;

typedef struct	s_res
{
  int		*list;
  int		size;
  int		max_cycle;
  struct s_res	*next;
}		t_res;

typedef struct	s_cor
{
  t_fil		*file;
  t_room	*rooms;
  t_fmi		*fourmis;
  t_bdg		*bridges;
  int		fourmis_nb;
  int		rooms_nb;
  t_sol		*sol;
  t_res		*res;
}		t_cor;

/*
** move_fourmis.c
*/
int	init_cycles(t_cor*);
int	init_move_fourmis(t_cor*);
int	go_to_next_room(int, int*);
void	move_fourmis(t_cor*);

/*
** resolve_*.c
*/
int	my_size_int_tab(int*);
int	get_size_lists(t_res*);
void	order_lists(t_cor*);
int	*my_cpy_list(int*);
int	add_to_list_res(t_cor*, int*);
int	*my_add_list(int*, int);
void	get_nb_room(t_cor*);
t_sol	**get_nb_bridges(t_cor*, int);
int	is_good_bridge(t_bdg*, int, int*);
int	get_ways(t_cor*, t_sol*, int*, int);
void	proceed_fourmis(t_cor*);

/*
** list_*.c
*/
void	room_put_in_list(t_room**, char*, t_pos*, int);
void	room_free_list(t_room**);
int	room_get_id(t_room*, char*);
char	*room_get_name(t_room*, int);
int	room_get_start(t_room*);
int	room_get_end(t_room*);
void	file_put_in_list(t_fil**, char*);
void	file_free_list(t_fil**);
void	fourmi_put_in_list(t_fmi**, int, int);
void	fourmi_free_list(t_fmi**);
void	bridge_put_in_list(t_bdg**, int, int);
void	bridge_free_list(t_bdg**);

/*
** parsing.c
** parsing_pattern.c
*/
void	read_file(t_cor*);
void	parse_everything(t_cor*);
int	get_line_type(char*);

/*
** validate.c
*/
void	validate_everything(t_cor*);

/*
** misc.c
*/
char	*get_next_line(char*);
void	my_perror(char*);
void	my_error(char*);
void	free_wordtab(char**);

#endif /* !FOURMIZ_H_ */

