/*
** avance.c for zappy in /Users/vacqui_k/Zappy/zappy-2016-asvine_p/server
**
** Made by kevin vacquier
** Login   <vacqui_k@epitech.eu>
**
** Started on  Sat Jun 29 19:42:52 2013 kevin vacquier
** Last update Tue Jul  9 18:40:51 2013 kevin vacquier
*/

#include "zappy.h"

void		add_expulse(t_env *env, int cs)
{
  put_in_arg_list(&env->clt[cs], expulse, NULL);
}

void		do_expulse2(t_env *env, int cs, int pos)
{
  if (env->clt[cs].dir == 2)
    env->clt[pos].posx = ((env->clt[pos].posx == env->xwidth - 1) ? (0) :
			 (env->clt[pos].posx + 1));
  else
    env->clt[pos].posy = ((env->clt[pos].posy == env->ylength - 1) ? (0) :
			 (env->clt[pos].posy + 1));
}

void		send_expulse(t_env *env, int cs, int dest)
{
  int		dir;

  dir = broadcast_dir(dest, cs, env);
  sprintf(env->clt[dest].buf_write, "deplacement: %i\n", dir);
  xsend(dest, env->clt[dest].buf_write, strlen(env->clt[dest].buf_write), "exp");
}

void		do_expulse(t_env *env, int cs)
{
  int		pos;

  pos = 0;
  while (pos++ < MAXCLIENT + 5)
    {
      if (env->clt[cs].posx == env->clt[pos].posx &&
	  env->clt[cs].posy == env->clt[pos].posy && cs != (pos))
	{
	  if (env->clt[cs].dir == 0)
	    env->clt[pos].posx = ((env->clt[pos].posx == 0) ? (env->xwidth - 1) :
				    (env->clt[pos].posx - 1));
	  else if (env->clt[cs].dir == 1)
	    env->clt[pos].posy = ((env->clt[pos].posy == 0) ? (env->ylength - 1) :
				      (env->clt[pos].posy - 1));
	  else
	    do_expulse2(env, cs, pos);
	  sprintf(env->clt[pos].buf_write, "ppo %i %i %i %i\n", env->clt[pos].num_client,
		  env->clt[pos].posx, env->clt[pos].posy, DIR(env->clt[pos].dir));
	  xsend(env->cs_graphic, env->clt[pos].buf_write,
		strlen(env->clt[pos].buf_write), "expulse");
	  send_expulse(env, cs, pos);
	}
      pos++;
    }
  xsend(cs, "ok\n", 3, "ok\n");
}
