/*
** incantation.c for zappy in /Users/vacqui_k/Zappy/zappy-2016-asvine_p/server
**
** Made by kevin vacquier
** Login   <vacqui_k@epitech.eu>
**
** Started on  Sat Jun 29 19:42:52 2013 kevin vacquier
** Last update Wed Jul 10 16:21:04 2013 kevin vacquier
*/

#include "zappy.h"

static		int up_tab[7][7] =
  {
    {1, 1, 0, 0, 0, 0, 0},
    {2, 1, 1, 1, 0, 0, 0},
    {2, 2, 0, 1, 0, 2, 0},
    {4, 1, 1, 2, 0, 1, 0},
    {4, 1, 2, 1, 3, 0, 0},
    {6, 1, 2, 3, 0, 1, 0},
    {6, 2, 2, 2, 2, 2, 1}
  };

void		add_incantation(t_env *env, int cs)
{
  put_in_arg_list(&env->clt[cs], incantation, NULL);
}

void		level_up(t_env *env, int cs)
{
  int		pos;

  pos = 1;
  while (pos < MAXCLIENT + 5)
    {
      if (env->clt[cs].level == env->clt[pos].level &&
	  env->clt[cs].posx == env->clt[pos].posx &&
	  env->clt[cs].posy == env->clt[pos].posy)
	{
	  env->clt[pos].level += 1;
	  sprintf(env->clt[pos].buf_write, "niveau actuel : %i\n",
		  env->clt[pos].level);
	  xsend(pos, env->clt[pos].buf_write, strlen(env->clt[pos].buf_write),
		"lvl up");
	}
      if (pos < 7)
	{
	  env->map[(rand() % (env->xwidth))][(rand() % (env->ylength))].
	    n_ress[pos - 1] += up_tab[env->clt[cs].level][pos];
	  env->map[env->clt[cs].posx][env->clt[cs].posy].n_ress[pos - 1] -=
	    up_tab[env->clt[cs].level][pos];
	}
      pos++;
    }
}

void		up_fail(t_env *env, int cs)
{
  int		pos;

  pos = 0;
  while (pos < MAXCLIENT + 5)
    {
      if (env->clt[cs].level == env->clt[pos].level &&
	  env->clt[cs].posx == env->clt[pos].posx &&
	  env->clt[cs].posy == env->clt[pos].posy)
	{
	  sprintf(env->clt[pos].buf_write, "niveau actuel : %i\n",
		  env->clt[pos].level);
	  xsend(pos, env->clt[pos].buf_write, strlen(env->clt[pos].buf_write),
		"lvl up");
	}
      pos++;
    }
}

int		check_incantation(t_env *env, int cs)
{
  int		players;
  int		posx;
  int		posy;
  int		lvl;

  lvl = env->clt[cs].level - 1;
  players = count_player_case(env, cs);
  posx = env->clt[cs].posx;
  posy = env->clt[cs].posy;
  if (up_tab[lvl][0] <= players &&
      up_tab[lvl][1] <= env->map[posx][posy].n_ress[0] &&
      up_tab[lvl][2] <= env->map[posx][posy].n_ress[1] &&
      up_tab[lvl][3] <= env->map[posx][posy].n_ress[2] &&
      up_tab[lvl][4] <= env->map[posx][posy].n_ress[3] &&
      up_tab[lvl][5] <= env->map[posx][posy].n_ress[4] &&
      up_tab[lvl][6] <= env->map[posx][posy].n_ress[5])
    return (1);
  return (0);
}

void		do_incantation(t_env *env, int cs)
{
  char		tmp[BUF_SIZE];

  if (check_incantation(env, cs))
    {
      level_up(env, cs);
      sprintf(tmp, "pie %i %i 1\n", env->clt[cs].posx, env->clt[cs].posy);
      xsend(env->cs_graphic, tmp, strlen(tmp), "Level up");
      send_map(env);
      send_player_level(env, cs);
    }
  else
    {
      up_fail(env, cs);
      sprintf(tmp, "pie %i %i 0\n", env->clt[cs].posx, env->clt[cs].posy);
      xsend(env->cs_graphic, tmp, strlen(tmp), "Level fail");
    }
}
