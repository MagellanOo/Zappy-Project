/*
** init_fds.c for init_fds in /Users/vacqui_k/Zappy/zappy-2016-asvine_p/server
**
** Made by kevin vacquier
** Login   <vacqui_k@epitech.eu>
**
** Started on  Mon Jun 10 13:32:56 2013 kevin vacquier
** Last update Wed Jun 12 14:33:01 2013 kevin vacquier
*/

#include "zappy.h"

void		init_fds(t_env *env)
{
  unsigned int	i;
  unsigned int	j;

  i = 0;
  j = 1;
  env->clt_max = 0;
  env->clt_min = 0;
  FD_ZERO(&env->fd_read);
  FD_ZERO(&env->fd_write);
  while (i <= MAXCLIENT)
    {
      if (env->clt[i].type != FD_FREE)
	{
	  FD_SET(i, &env->fd_read);
	  if (strlen(env->clt[i].buf_write) > 0)
	    FD_SET(i, &env->fd_write);
	  if (j++ == 1)
	    env->clt_min = MIN(i, env->clt_max);
	  env->clt_max = MAX(env->clt_max, i);
	}
      i++;
    }
  env->first++;
}
