/*
** init_graph.c for ZAPPY in /Users/vacqui_k/Zappy/zappy-2016-asvine_p/server
**
** Made by kevin vacquier
** Login   <vacqui_k@epitech.eu>
**
** Started on  Wed Jun 12 13:57:13 2013 kevin vacquier
** Last update Tue Jul  9 19:11:10 2013 kevin vacquier
*/

#include "zappy.h"

void		send_map(t_env *env)
{
  char		tmp[BUF_SIZE];
  unsigned int	x;
  unsigned int	y;

  x = 0;
  while (x < env->xwidth)
    {
      y = 0;
      while (y < env->ylength)
	{
	  sprintf(tmp, "bct %i %i %i %i %i %i %i %i %i\n", x, y,
		  env->map[x][y].n_ress[6], env->map[x][y].n_ress[0],
		  env->map[x][y].n_ress[1], env->map[x][y].n_ress[2],
		  env->map[x][y].n_ress[3], env->map[x][y].n_ress[4],
		  env->map[x][y].n_ress[5]);
	  xsend(env->cs_graphic, tmp, strlen(tmp), "send map");
	  y++;
	}
      x++;
    }
}

void		send_players(t_env *env)
{
  int		pos;
  char		tmp[BUF_SIZE];

  pos = env->nb_team;
  while (pos < MAXCLIENT + 5)
    {
      if (env->clt[pos].level && env->clt[pos].state == alive && env->clt[pos].inteam)
	{
	  sprintf(tmp, "pnw %i %i %i %i %i %i\n", env->clt[pos].num_client,
		  env->clt[pos].posx, env->clt[pos].posy, DIR(env->clt[pos].dir),
		  env->clt[pos].level, env->clt[pos].num_team);
	  xsend(env->cs_graphic, tmp, strlen(tmp), "player");
	}
      pos++;
    }
  pos = 0;
  while (pos < MAXCLIENT + 5)
    if (env->clt[pos++].state == inegg)
      {
	sprintf(tmp, "enw %i %i %i %i\n", env->clt[pos - 1].num_client_egg,
		env->clt[pos - 1].num_client, env->clt[pos - 1].posx,
		env->clt[pos - 1].posy);
	xsend(env->cs_graphic, tmp, strlen(tmp), "player");
      }
}

void	send_player_level(t_env *env, int cs)
{
  int		pos;
  char		tmp[BUF_SIZE];

  pos = 0;
  while (pos < MAXCLIENT + 5)
    {
      if (env->clt[pos].level == env->clt[cs].level)
	{
	  sprintf(tmp, "plv %i %i\n", pos, env->clt[pos].level);
	  xsend(env->cs_graphic, tmp, strlen(tmp), "player");
	}
      pos++;
    }
}

void	send_team(t_env *env)
{
  int		pos;
  char		tmp[BUF_SIZE];

  pos = 1;
  while (pos <= env->nb_team)
    {
      sprintf(tmp, "tna %s\n", env->clt[pos].name_of_team);
      xsend(env->cs_graphic, tmp, strlen(tmp), "sendteam");
      pos++;
    }
}

void	init_graph(t_env *env, int cs)
{
  env->clt[cs].type = FD_GRAPH;
  env->cs_graphic = cs;
  env->clt[cs].g = 2;
  env->first = 1;
  sprintf(env->clt[cs].buf_write, "msz %i %i\n",
	  env->xwidth, env->ylength);
  xsend(env->cs_graphic, env->clt[cs].buf_write,
	strlen(env->clt[cs].buf_write), "G");
  sprintf(env->clt[cs].buf_write, "sgt %i\n",
	  (int)(env->timeunity));
  xsend(env->cs_graphic, env->clt[cs].buf_write,
	strlen(env->clt[cs].buf_write), "G");
  send_map(env);
  send_team(env);
  send_players(env);
}
