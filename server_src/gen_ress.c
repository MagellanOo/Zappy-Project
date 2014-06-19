/*
** gen_ress.c for gen_ress in /Users/vacqui_k/Zappy/zappy-2016-asvine_p/server
**
** Made by kevin vacquier
** Login   <vacqui_k@epitech.eu>
**
** Started on  Thu Jun  6 22:44:34 2013 kevin vacquier
** Last update Fri Jul 12 20:06:38 2013 KÃ©vin VACQUIER
*/

#include "zappy.h"

void		init_case_map(t_env *env)
{
  unsigned int	x;
  unsigned int	y;

  x = 0;
  while (x < env->xwidth)
    {
      y = 0;
      while (y < env->ylength)
	{
	  env->map[x][y].n_ress[0] = 0;
	  env->map[x][y].n_ress[1] = 0;
	  env->map[x][y].n_ress[2] = 0;
	  env->map[x][y].n_ress[3] = 0;
	  env->map[x][y].n_ress[4] = 0;
	  env->map[x][y].n_ress[5] = 0;
	  env->map[x][y].n_ress[6] = 0;
	  y++;
	}
      x++;
    }
}

void		gen_ress(t_env *env)
{
  unsigned int	i;
  unsigned int	posx;
  int		posy;
  int		res;

  env->tot_res = (env->xwidth * env->ylength);
  env->tot_res += rand() % (env->xwidth * env->ylength);
  env->map = xmalloc(sizeof(*env->map) * (env->xwidth + 1));
  posx = 0;
  while (posx <= env->xwidth)
      env->map[posx++] = xmalloc(sizeof(**env->map) * (env->ylength + 1));
  init_case_map(env);
  i = 0;
  while (i < env->tot_res)
    {
      posx = (rand() % (env->xwidth));
      posy = (rand() % (env->ylength));
      res = (rand() % 10);
      if (res > 6)
	env->map[posx][posy].n_ress[6] += 1;
      else
	env->map[posx][posy].n_ress[res] += 1;
      i++;
    }
  puts("INFO : 4/4 The map is ready");
}
