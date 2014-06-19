/*
** voir.c for zappy in /Users/vacqui_k/Zappy/zappy-2016-asvine_p/server
**
** Made by kevin vacquier
** Login   <vacqui_k@epitech.eu>
**
** Started on  Sat Jun 29 19:42:52 2013 kevin vacquier
** Last update Wed Jul 10 15:55:01 2013 kevin vacquier
*/

#include "zappy.h"

void		add_voir(t_env *env, int cs)
{
  put_in_arg_list(&env->clt[cs], voir, NULL);
}

int		calc_x(t_env *env, int cs, int x)
{
  int	val;

  if (x < 0)
    val = env->xwidth - x - 1;
  else if ((unsigned int)x >= env->xwidth)
    val = x - env->xwidth;
  else
    val = x;
  cs++;
  return (val);
}

int		calc_y(t_env *env, int cs, int y)
{
  int	val;

  if (y < 0)
    val = env->ylength - y - 1;
  else if ((unsigned int)y >= env->ylength)
    val = y - env->ylength;
  else
    val = y;
  cs++;
  return (val);
}

void		cat_case(t_env *env, int cs, int x, int y)
{
  printf("cat case %i %i\n", x, y);
  if (env->map[x][y].n_ress[0] > 0)
    strcat(env->clt[cs].buf_write, " linemate");
  if (env->map[x][y].n_ress[1] > 0)
    strcat(env->clt[cs].buf_write, " deraumere");
  if (env->map[x][y].n_ress[2] > 0)
    strcat(env->clt[cs].buf_write, " sibur");
  if (env->map[x][y].n_ress[3] > 0)
    strcat(env->clt[cs].buf_write, " mendiane");
  if (env->map[x][y].n_ress[4] > 0)
    strcat(env->clt[cs].buf_write, " phiras");
  if (env->map[x][y].n_ress[5] > 0)
    strcat(env->clt[cs].buf_write, " thystame");
  if (env->map[x][y].n_ress[6] > 0)
    strcat(env->clt[cs].buf_write, " nourriture");
  if (see_player_case(env, cs, x, y))
    strcat(env->clt[cs].buf_write, " joueur");
  strcat(env->clt[cs].buf_write, ",");
}

void		do_voir(t_env *env, int cs)
{
  if (env->clt[cs].dir == 0)
    voir_0(env, cs);
  if (env->clt[cs].dir == 1)
    voir_1(env, cs);
  if (env->clt[cs].dir == 2)
    voir_2(env, cs);
  if (env->clt[cs].dir == 3)
    voir_3(env, cs);
  env = NULL;
}
