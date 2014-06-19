/*
** avance.c for zappy in /Users/vacqui_k/Zappy/zappy-2016-asvine_p/server
**
** Made by kevin vacquier
** Login   <vacqui_k@epitech.eu>
**
** Started on  Sat Jun 29 19:42:52 2013 kevin vacquier
** Last update Mon Jul  8 21:06:47 2013 kevin vacquier
*/

#include "zappy.h"

void		add_avance(t_env *env, int cs)
{
  put_in_arg_list(&env->clt[cs], avance, NULL);
}

void		do_avance2(t_env *env, int cs)
{
  if (env->clt[cs].dir == 2)
    env->clt[cs].posx = ((env->clt[cs].posx == env->xwidth) ? (0) :
			 (env->clt[cs].posx + 1));
  else
    env->clt[cs].posy = ((env->clt[cs].posy == env->ylength) ? (0) :
			 (env->clt[cs].posy + 1));
}

void		do_avance(t_env *env, int cs)
{
  if (env->clt[cs].dir == 0)
    env->clt[cs].posx = ((env->clt[cs].posx == 0) ? (env->xwidth) :
			 (env->clt[cs].posx - 1));
  else if (env->clt[cs].dir == 1)
    env->clt[cs].posy = ((env->clt[cs].posy == 0) ? (env->ylength) :
			 (env->clt[cs].posy - 1));
  else
    do_avance2(env, cs);
  sprintf(env->clt[cs].buf_write, "ppo %i %i %i %i\n", env->clt[cs].num_client,
	  env->clt[cs].posx, env->clt[cs].posy, DIR(env->clt[cs].dir));
  xsend(env->cs_graphic, env->clt[cs].buf_write, strlen(env->clt[cs].buf_write)
	, "avance");
  xsend(cs, "ok\n", 3, "ok\n");
}
