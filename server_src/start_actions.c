/*
** start_incant.c for start_incantation in /Users/vacqui_k/Zappy/zappy-2016-asvine_p/server
**
** Made by kevin vacquier
** Login   <vacqui_k@epitech.eu>
**
** Started on  Mon Jul  8 13:31:47 2013 kevin vacquier
** Last update Wed Jul 10 12:08:54 2013 kevin vacquier
*/

#include "zappy.h"

void		start_incantation(t_env *env, int cs)
{
  char		tmp[BUF_SIZE];
  char		tmp2[BUF_SIZE];
  unsigned int	pos;

  pos = 0;
  sprintf(tmp, "pic %i %i %i", env->clt[cs].posx, env->clt[cs].posy,
	  env->clt[cs].level);
  while (pos <= env->nfds)
    {
      if (env->clt[cs].level == env->clt[pos].level &&
	  env->clt[cs].posx == env->clt[pos].posx &&
	  env->clt[cs].posy == env->clt[pos].posy)
	{
	  sprintf(tmp2, " %i", env->clt[cs].level);
	  strcat(tmp, tmp2);
	  xsend(pos, "elevation en cours\n", 19, "elevation");
	}
      pos++;
    }
  strcat(tmp, "\n");
  xsend(env->cs_graphic, tmp, strlen(tmp), "upper");
}

void		start_egg(t_env *env, int cs)
{
    sprintf(env->clt[cs].buf_write, "pfk %i\n", env->clt[cs].num_client);
    xsend(env->cs_graphic, env->clt[cs].buf_write,
	  strlen(env->clt[cs].buf_write), "start_egg");
}
