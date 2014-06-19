/*
** egg.c for zappy in /Users/vacqui_k/Zappy/zappy-2016-asvine_p/server
**
** Made by kevin vacquier
** Login   <vacqui_k@epitech.eu>
**
** Started on  Sat Jun 29 19:42:52 2013 kevin vacquier
** Last update Wed Jul 10 14:39:21 2013 kevin vacquier
*/

#include "zappy.h"

void		clean_egg(t_env *env,int cs)
{
  if (env->clt[cs].type == 0)
    if (close(cs) == -1)
      perror("close");
  env->nb_co--;
  env->clt[cs].state = dead;
  env->clt[cs].inteam = -1;
  env->clt[cs].level = -1;
  env->numegg--;
  env->clt[cs].posyegg = -1;
  env->clt[cs].posxegg = -1;
}

void		init_egg(t_env *env, int cs)
{
  if (env->clt[cs].type == FD_CLIENT)
    {
      env->clt[cs].state = 0;
      env->nb_co -= 1;
      env->clt[cs].inteam = 0;
      env->clt[cs].posx = env->clt[cs].posxegg;
      env->clt[cs].posy = env->clt[cs].posyegg;
      env->clt[cs].level = INIT_LVL;
      env->clt[cs].g = 0;
      env->clt[cs].dir = (rand() % 4) + 1;
    }
}

void		add_egg(t_env *env, int cs)
{
  put_in_arg_list(&env->clt[cs], egg, NULL);
}

void		call_egg(t_env *env, int cs)
{
  int		i;

  i = env->nb_team;
  while (i < MAXCLIENT + 5)
    {
      if (env->clt[i].type == FD_FREE)
	{
	  env->clt[i].type = FD_CLIENT;
	  env->clt[i].num_client_egg = ++env->numegg;
	  env->clt[i].state = inegg;
	  env->clt[i].num_client = ++env->nb_co;
	  env->clt[i].posxegg = env->clt[cs].posx;
	  env->clt[i].posyegg = env->clt[cs].posy;
	  env->clt[i].num_team = env->clt[cs].num_team;
	  strcpy(env->clt[i].name_of_team, env->clt[cs].name_of_team);
	  sprintf(env->clt[cs].buf_write, "enw %i %i %i %i\n",
		  env->clt[i].num_client_egg, env->clt[cs].num_client,
		  env->clt[i].posxegg, env->clt[i].posyegg);
	  xsend(env->cs_graphic, env->clt[cs].buf_write,
		strlen(env->clt[cs].buf_write), "Xegg");
	  break ;
	}
      i++;
    }
}

void		do_egg(t_env *env, int cs)
{
  call_egg(env, cs);
  xsend(env->cs_graphic, env->clt[cs].buf_write, strlen(env->clt[cs].buf_write),
	"egg");
  xsend(cs, "ok\n", 3, "fork");
}
