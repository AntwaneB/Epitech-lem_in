/*
** main.c for Project Name in /home/buchse_a/Scripts/build
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Mon Apr 14 10:34:44 2014 Antoine Buchser
** Last update Wed Apr 30 16:13:15 2014 Thomas MORITZ
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "fourmiz.h"

int	is_room(char *str)
{
  char	**wordtab;
  int	i;
  int	check;

  check = 0;
  wordtab = my_str_to_wordtab(str);
  i = 0;
  while (wordtab && wordtab[i])
    i++;
  if (i == 3
      && my_str_isnum(wordtab[1])
      && my_str_isnum(wordtab[2]))
    check = 1;
  free_wordtab(wordtab);
  return (check);
}

int	count_words(char *str)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (str && str[i])
    {
      if (i > 0 && (str[i] == ' ' || str[i] == '\t')
	  && str[i - 1] != ' ' && str[i - 1] != '\t')
	nb++;
      else if (i == 0 && str[i] != ' ' && str[i] != '\t')
	nb++;
      i++;
    }
  return (nb);
}

int	is_bridge(char *str)
{
  int	i;
  int	check;
  int	error;

  error = 0;
  check = 0;
  if (count_words(str) != 1)
    return (0);
  i = 0;
  while (str[i] && !error)
    {
      if (i > 0 && check == 0 && str[i] == '-')
	check = 1;
      else if (i > 0 && check == 1 && str[i] == '-')
	error++;
      else if (i == 0 && str[i] == '-')
	error++;
      else if (i == my_strlen(str) - 1 && str[i] == '-')
	error++;
      i++;
    }
  return ((!error) ? check : -1);
}

int	get_line_type(char *line)
{
  if (!my_strcmp(line, "##start"))
    return (START);
  else if (!my_strcmp(line, "##end"))
    return (END);
  else if (line[0] == '#')
    return (COMMENT);
  else if (my_str_isnum(line))
    return (FOURMIS_NB);
  else if (is_bridge(line))
    return (BRIDGE);
  else if (is_room(line))
    return (ROOM);
  else
    my_error("Invalid file.\n");
  return (-1);
}
