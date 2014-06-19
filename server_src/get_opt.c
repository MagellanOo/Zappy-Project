/*
** get_opt.c for ZAPPY in /Users/vacqui_k/Zappy/server
**
** Made by kevin vacquier
** Login   <vacqui_k@epitech.eu>
**
** Started on  Tue Jun  4 10:56:49 2013 kevin vacquier
** Last update Fri Jul 12 20:05:28 2013 KÃ©vin VACQUIER
*/

#include "zappy.h"

typedef struct s_opt
{
  char		opt[3];
  int		(*fct)(t_env *env, char **av, int i);
}		t_opt;

static t_opt		cmd[] =
  {
    {"-p", getport},
    {"-x", getx},
    {"-y", gety},
    {"-n", getteam},
    {"-c", getlimteam},
    {"-t", gettime}
  };

int	getport(t_env *env, char ** av, int i)
{
  env->port = atoi(av[i + 1]);
  return ((env->port > 0) ? 1 : 0);
}

void	get_opt(t_env *env, int ac, char **av)
{
  int	i;
  int   j;

  i = 0;
  j = 0;
  while (ac > 11 && i < ac - 1)
    {
      if (strcmp(av[i], cmd[j].opt) == 0)
	{
	  if (!cmd[j].fct(env, av, i))
	    exit (-1);
	  j++;
	}
      i++;
    }
  if (j != 6)
    {
      fprintf(stderr, USAGE, av[0]);
      exit(-1);
    }
  puts("INFO : 2/4 Args parsed");
}
