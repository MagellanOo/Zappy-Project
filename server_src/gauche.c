/*
** gauche.c for zappy in /Users/vacqui_k/Zappy/zappy-2016-asvine_p/server
**
** Made by kevin vacquier
** Login   <vacqui_k@epitech.eu>
**
** Started on  Sat Jun 29 19:42:52 2013 kevin vacquier
** Last update Mon Jul  8 21:06:33 2013 kevin vacquier
*/

#include "zappy.h"

void		add_droite(t_env *env, int cs)
{
  put_in_arg_list(&env->clt[cs], droite, NULL);
}

void		do_droite(t_env *env, int cs)
{
  env->clt[cs].dir = ((env->clt[cs].dir == 3) ? (0) : (env->clt[cs].dir + 1));
  sprintf(env->clt[cs].buf_write, "ppo %i %i %i %i\n", env->clt[cs].num_client,
	  env->clt[cs].posx, env->clt[cs].posy, DIR(env->clt[cs].dir));
  xsend(env->cs_graphic, env->clt[cs].buf_write, strlen(env->clt[cs].buf_write)
	, "avance");
  xsend(cs, "ok\n", 3, "ok\n");
}
