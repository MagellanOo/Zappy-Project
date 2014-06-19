/*
** apply_timers.c for apply_tu in /Users/vacqui_k/Zappy/zappy-2016-asvine_p/server
**
** Made by kevin vacquier
** Login   <vacqui_k@epitech.eu>
**
** Started on  Sun Jun 30 20:24:35 2013 kevin vacquier
** Last update Fri Jul 12 19:43:55 2013 KÃ©vin VACQUIER
*/

#include "zappy.h"

void		apply_timer_rot(t_env *env, int cs)
{
  env->clt[cs].timer -= env->elapsed_time;
  if (env->clt[cs].timer <= -600)
    clean_egg(env, cs);
}

void		apply_timer_egg(t_env *env, int cs)
{
  char		tmp[42];

  env->clt[cs].timer -= env->elapsed_time;
  if (env->clt[cs].timer <= -600)
    {
      env->clt[cs].inteam = 1;
      env->clt[cs].type = FD_CLIENT;
      env->clt[cs].posx = env->clt[cs].posxegg;
      env->clt[cs].posy = env->clt[cs].posyegg;
      env->clt[cs].posxegg = 0;
      env->clt[cs].posyegg = 0;
      env->clt[cs].timer = 0;
      env->clt[cs].eat_timer = 0;
      sprintf(tmp, "eht %i\n", env->clt[cs].num_client_egg);
      xsend(env->cs_graphic, tmp, strlen(tmp), "egg_tim");
    }
}

static void	print_case(t_env *env, int x, int y)
{
  unsigned short	*mr;
  int			len;
  char			tmp[BUF_SIZE];

  mr = env->map[x][y].n_ress;
  sprintf(tmp, "bct %i %i %i %i %i %i %i %i %i\n", x, y,
	  mr[6], mr[0], mr[1], mr[2], mr[3], mr[4], mr[5]);
  len = strlen(tmp);
  xsend(env->cs_graphic, tmp, len, "prendre");

}

void		apply_timer_player(t_env *env, int cs)
{
  int		x;
  int		y;

  env->clt[cs].timer -= env->elapsed_time;
  env->clt[cs].eat_timer -= env->elapsed_time;
  if (env->clt[cs].eat_timer <= -1260)
    {
      env->clt[cs].bag[0] -= 1;
      env->clt[cs].eat_timer += 126;
      x = rand() % env->xwidth;
      y = rand() % env->ylength;
      env->map[x][y].n_ress[6] += 1;
      print_case(env, x, y);
      if (env->clt[cs].bag[0] < 0)
	{
	  sprintf(env->clt[cs].buf_write, "pdi %i\n", env->clt[cs].num_client);
	  xsend(env->cs_graphic, env->clt[cs].buf_write,
		strlen(env->clt[cs].buf_write), "DIE");
	  clean_client(env, cs);
	}
    }
}

void		apply_timers(t_env *env)
{
  unsigned int	i;

  i = 1;
  while (i <= env->nfds + env->numegg)
    {
      if (env->clt[i].state == alive && env->clt[i].inteam == 1)
	apply_timer_player(env, i);
      else if (env->clt[i].state == inegg && env->clt[i].num_client_egg)
	apply_timer_egg(env, i);
      else if (env->clt[i].state == alive && env->clt[i].num_client_egg)
	apply_timer_rot(env, i);
      i++;
    }
}
