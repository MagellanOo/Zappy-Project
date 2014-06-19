/*
** connect_nbr.c for connect in /Users/vacqui_k/Zappy/zappy-2016-asvine_p/server
**
** Made by kevin vacquier
** Login   <vacqui_k@epitech.eu>
**
** Started on  Sun Jun 30 00:34:10 2013 kevin vacquier
** Last update Mon Jul  8 19:28:05 2013 kevin vacquier
*/

#include "zappy.h"

void		add_connect_nbr(t_env *env, int cs)
{
  put_in_arg_list(&env->clt[cs], connect_nbr, NULL);
}

void		do_connect_nbr(t_env *env, int cs)
{
  sprintf(env->clt[cs].buf_write, "%i\n",
	  env->clt[env->clt[cs].num_team].nbclient);
  xsend(cs, env->clt[cs].buf_write, strlen(env->clt[cs].buf_write), "connctnr");
}
