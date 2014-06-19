/*
** get_opt_fnct.c for ZAPPY in /Users/vacqui_k/Zappy/server
**
** Made by kevin vacquier
** Login   <vacqui_k@epitech.eu>
**
** Started on  Tue Jun  4 11:00:14 2013 kevin vacquier
** Last update Thu Jul 11 18:57:47 2013 KÃ©vin VACQUIER
*/

#include "zappy.h"

int	gettime(t_env *env, char **av, int i)
{
  if (av[i + 1])
    env->timeunity = atof(av[i + 1]);
  return ((env->timeunity <= 0) ? (0) : (1));
}

int	getteam(t_env *env, char **av, int i)
{
  int	j;

  j = 1;
  while (av[i + 1][0] != '-')
    {
      if (!strncmp(av[i + 1], "GRAPHIC", 7))
	{
	  puts("GRAPHIC IS NOT A TEAMNAME");
	  exit(-1);
	}
      env->clt[j].nbclient = env->nb_client;
      strncpy(env->clt[j].name_of_team, av[i + 1], strlen(av[i + 1]));
      env->nb_team = j;
      j++;
      i++;
    }
  env->nb_client_tot = (env->nb_team + 1) * env->nb_client;
  if (env->nb_client_tot > MAXCLIENT)
    {
      fprintf(stderr, OPT_MAX_CLIENT);
      exit(1);
    }
  return (strcmp(env->clt[1].name_of_team, "\0") == 0 ? 0 : 1);
}

int	getlimteam(t_env *env, char **av, int i)
{
  unsigned int	pos_client;

  pos_client = 0;
  env->nb_client = atoi(av[i + 1]);
  while (pos_client < env->nb_client_tot + 5)
    env->clt[pos_client++].nbclient = env->nb_client;
  return ((env->nb_client > 0) ? 1 : 0);
}

int	getx(t_env *env, char ** av, int i)
{
  env->xwidth = atoi(av[i + 1]);
  return ((env->xwidth > 0) ? 1 : 0);
}

int	gety(t_env *env, char ** av, int i)
{
  env->ylength = atoi(av[i + 1]);
  return ((env->ylength > 0) ? 1 : 0);
}
