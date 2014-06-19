/*
** count_player_case.c for zappy in /Users/vacqui_k/Zappy/zappy-2016-asvine_p/server
**
** Made by kevin vacquier
** Login   <vacqui_k@epitech.eu>
**
** Started on  Sun Jul  7 22:47:31 2013 kevin vacquier
** Last update Tue Jul  9 19:09:36 2013 kevin vacquier
*/

#include "zappy.h"

int		count_player_case(t_env *env, int cs)
{
  int		nb;
  int		pos;

  pos = 0;
  nb = 0;
  while (pos < MAXCLIENT + 5)
    {
      if (env->clt[cs].level == env->clt[pos].level &&
	  env->clt[cs].posx == env->clt[pos].posx &&
	  env->clt[cs].posy == env->clt[pos].posy)
	nb++;
      pos++;
    }
  return (nb);
}

int		see_player_case(t_env *env, int cs, int x, int y)
{
  int		nb;
  int		pos;

  pos = 0;
  nb = 0;
  while (pos < MAXCLIENT + 5)
    {
      if ((unsigned int)x == env->clt[pos].posx &&
	  (unsigned int)y == env->clt[pos].posy && pos != cs)
	nb++;
      pos++;
    }
  return (nb);
}
