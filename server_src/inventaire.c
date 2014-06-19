/*
** inventaire.c for zappy in /Users/vacqui_k/Zappy/zappy-2016-asvine_p/server
**
** Made by kevin vacquier
** Login   <vacqui_k@epitech.eu>
**
** Started on  Sat Jun 29 19:42:52 2013 kevin vacquier
** Last update Tue Jul  9 18:57:58 2013 kevin vacquier
*/

#include "zappy.h"

void		add_inventaire(t_env *env, int cs)
{
  put_in_arg_list(&env->clt[cs], inventaire, NULL);
}

void		do_inventaire(t_env *env, int cs)
{
  char		tmp[BUF_SIZE];

  sprintf(env->clt[cs].buf_write, "{nourriture %i, linemate %i, deraumere %i,",
	  env->clt[cs].bag[6],
	  env->clt[cs].bag[0], env->clt[cs].bag[1]);
  sprintf(tmp, " sibur %i, mendiane %i, phiras %i, thystame %i}\n",
	  env->clt[cs].bag[2], env->clt[cs].bag[3], env->clt[cs].bag[4],
	  env->clt[cs].bag[5]);
  strcat(env->clt[cs].buf_write, tmp);
  xsend(cs, env->clt[cs].buf_write, strlen(env->clt[cs].buf_write), "invent");
}
