/*
** pose.c for zappy.c in /Users/vacqui_k/Zappy/zappy-2016-asvine_p/server
**
** Made by kevin vacquier
** Login   <vacqui_k@epitech.eu>
**
** Started on  Sun Jun 30 12:56:41 2013 kevin vacquier
** Last update Tue Jul  9 17:48:11 2013 kevin vacquier
*/

#include "zappy.h"

static char		*prd[9] =
  {
    "linemate", "deraumere", "sibur", "mendiane",
    "phiras", "thystame", "food"
  };

void			add_pose(t_env *env, int cs)
{
  put_in_arg_list(&env->clt[cs], pose, env->clt[cs].buf_read);
}

static void    		pose_send(t_env *env, int cs)
{
  int			len;

  len = strlen(env->clt[cs].buf_write);
  xsend(env->cs_graphic, env->clt[cs].buf_write, len, "pose");
}

void			do_pose_2(t_env *env, int cs, int ress, int *pr)
{
  int			x;
  int			y;
  unsigned short	*mr;

  x = env->clt[cs].posx;
  y = env->clt[cs].posy;
  if (pr[ress] > 0)
    {
      env->map[x][y].n_ress[ress] += 1;
      env->clt[cs].bag[ress] -= 1;
      mr = env->map[x][y].n_ress;
      sprintf(env->clt[cs].buf_write, "pdr %i %i\n",
	      env->clt[cs].num_client, ress);
      pose_send(env, cs);
      sprintf(env->clt[cs].buf_write, "pin %i %i %i %i %i %i %i %i %i %i\n",
	      env->clt[cs].num_client, x, y, pr[6], pr[0], pr[1], pr[2], pr[3], pr[4],
	      pr[5]);
      pose_send(env, cs);
      sprintf(env->clt[cs].buf_write, "bct %i %i %i %i %i %i %i %i %i\n", x, y,
	      mr[6], mr[0], mr[1], mr[2], mr[3], mr[4], mr[5]);
      pose_send(env, cs);
      xsend(cs, "ok\n", 3, "pose");
    }
  else
    xsend(cs, "ko\n", 3, "pose");
}


void			do_pose(t_env *env, int cs)
{
  char			*arg;
  int			i;

  i = 0;
  arg = env->clt[cs].act_list[0].arg;
  arg += strlen("pose ");
  while (i < 7 && strncmp(arg, prd[i], strlen(prd[i])))
    i++;
  if (i == 7)
    xsend(cs, "ko\n", 3, "pose");
  else
    do_pose_2(env, cs, i, env->clt[cs].bag);
}
