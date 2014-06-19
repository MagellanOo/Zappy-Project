/*
** broadcast.c for zappy in /Users/vacqui_k/Zappy/zappy-2016-asvine_p/server
**
** Made by kevin vacquier
** Login   <vacqui_k@epitech.eu>
**
** Started on  Sun Jun 30 12:56:35 2013 kevin vacquier
** Last update Wed Jul 10 10:31:52 2013 kevin vacquier
*/

#include "zappy.h"
typedef struct s_dir
{
  unsigned int	cmp;
  double anglecmp;
  unsigned int dir;
}	t_dir;

static t_dir	tab1[] =
  {
    {0, 30, 3},
    {0, 60, 4},
    {0, 90, 5},
    {1, 30, 5},
    {1, 60, 6},
    {1, 90, 7},
    {2, 30, 7},
    {2, 60, 8},
    {2, 90, 1},
    {4, 30, 1},
    {4, 60, 2},
    {4, 90, 3},
    {-1, -1, -1}
  };

static t_dir	tab2[] =
  {
    {0, 30, 5},
    {0, 60, 6},
    {0, 90, 7},
    {1, 30, 7},
    {1, 60, 8},
    {1, 90, 1},
    {2, 30, 1},
    {2, 60, 2},
    {2, 90, 3},
    {4, 30, 3},
    {4, 60, 4},
    {4, 90, 5},
    {-1, -1, -1}
  };

static t_dir	tab3[] =
  {
    {0, 30, 7},
    {0, 60, 8},
    {0, 90, 1},
    {1, 30, 1},
    {1, 60, 2},
    {1, 90, 3},
    {2, 30, 3},
    {2, 60, 4},
    {2, 90, 5},
    {4, 30, 5},
    {4, 60, 6},
    {4, 90, 7},
    {-1, -1, -1}
  };

static t_dir	tab4[] =
  {
    {0, 30, 1},
    {0, 60, 2},
    {0, 90, 3},
    {1, 30, 3},
    {1, 60, 4},
    {1, 90, 5},
    {2, 30, 5},
    {2, 60, 6},
    {2, 90, 7},
    {4, 30, 7},
    {4, 60, 8},
    {4, 90, 1},
    {-1, -1, -1}
  };

void		add_broadcast(t_env *env, int cs)
{
  put_in_arg_list(&env->clt[cs], broadcast, env->clt[cs].buf_read);
}

unsigned int	calc_angle(t_env *env, int x2, int x1, t_dir *tab)
{
  double	teta;
  double	res;
  unsigned int	dir;
  int		i;

  i = 0;
  teta = atan((double)((fabs(env->clt[x1].posy - env->clt[x2].posy))
		       / fabs((env->clt[x1].posx - env->clt[x2].posx))));
  teta = teta * 180 / M_PI;
  res = 90 - teta;
  while (i < 13)
    {
      if ((tab[i].cmp == env->clt[x2].dir)
	  && ((tab[i].anglecmp - 30) <= res)
	  && (res <= tab3[i].anglecmp))
	dir = tab[i].dir;
      i++;
    }
  return (dir);
}

unsigned int	broadcast_dir(int dest, int cs, t_env *env)
{
  if ((env->clt[cs].posx >= env->clt[dest].posx)
      && (env->clt[cs].posy >= env->clt[dest].posy))
    return (calc_angle(env, dest, cs, tab1));
  else if ((env->clt[cs].posx > env->clt[dest].posx)
	   && (env->clt[cs].posy < env->clt[dest].posy))
    return (calc_angle(env, dest, cs, tab2));
  else if ((env->clt[cs].posx <= env->clt[dest].posx)
	   && (env->clt[cs].posy <= env->clt[dest].posy))
    return (calc_angle(env, dest, cs, tab3));
  else
    return (calc_angle(env, dest, cs, tab4));
}

void		send_broadcast(int dest, int cs, t_env *env, int dir)
{
  char		msgsend[BUF_SIZE];

  memset(msgsend, '\0', strlen(msgsend));
  if ((env->clt[cs].posx == env->clt[dest].posx)
      && (env->clt[cs].posy == env->clt[dest].posy))
    sprintf(msgsend, "message 0,%s\n",
	    env->clt[cs].act_list[0].arg + 10);
  else
    sprintf(msgsend, "message %i,%s\n",
	    dir, env->clt[cs].act_list[0].arg + 10);
  xsend(dest, msgsend, strlen(msgsend), "pbc");
}

void		do_broadcast(t_env *env, int cs)
{
  unsigned int	i;
  unsigned int	dir;

  i = 0;
  dir = 0;
  while (i <= env->nfds)
    {
      if ((env->clt[cs].state == 0) && (env->clt[i].state == 0)
	  && (env->clt[i].type == FD_CLIENT)
	  && (env->clt[cs].type == FD_CLIENT) && ((int)i != (cs)))
	{
	  dir = broadcast_dir(i, cs, env);
	  send_broadcast(i, cs, env, dir);
	}
      i++;
    }
  xsend(cs, "ok\n", 3, "broadok");
}
