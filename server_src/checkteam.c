/*
** checkteam.c for zappy.c in /Users/vacqui_k/Zappy/zappy-2016-asvine_p/server
**
** Made by kevin vacquier
** Login   <vacqui_k@epitech.eu>
**
** Started on  Sun Jun 30 01:17:28 2013 kevin vacquier
** Last update Wed Jul 10 15:47:36 2013 kevin vacquier
*/

#include "zappy.h"

void		verifonecase(t_env *env, int cs)
{
  t_case	**m;
  int		x;
  int		y;

  x = env->clt[cs].posx;
  y = env->clt[cs].posy;
  m = env->map;
  printf("bct X %i Y %i %i %i %i %i %i %i %i\n",
	 x, y, m[x][y].n_ress[0], m[x][y].n_ress[1],
	 m[x][y].n_ress[2], m[x][y].n_ress[3], m[x][y].n_ress[4],
	 m[x][y].n_ress[5], m[x][y].n_ress[6]);
}

void		verifeachcase(t_env *env)
{
  t_case	**m;
  unsigned int	x;
  unsigned int	y;

  m = env->map;
  x = 0;
  while (x < env->xwidth)
    {
      y = 0;
      while (y < env->ylength)
	{
	  printf("bct X %i Y %i %i %i %i %i %i %i %i\n",
		 x, y, m[x][y].n_ress[0], m[x][y].n_ress[1],
		 m[x][y].n_ress[2], m[x][y].n_ress[3], m[x][y].n_ress[4],
		 m[x][y].n_ress[5], m[x][y].n_ress[6]);
	  y++;
	}
      x++;
    }
}

void		initcordonneeclter(t_env *env, int cs)
{
  char		tmp[BUF_SIZE];

  env->clt[cs].posx = (rand() % env->xwidth);
  env->clt[cs].posy = (rand() % env->ylength);
  env->clt[cs].dir = (rand() % 4);
  sprintf(tmp, "pnw %i %i %i %i %i %s\n", env->clt[cs].num_client, env->clt[cs].posx,
	   env->clt[cs].posy, env->clt[cs].dir, env->clt[cs].level,
	   env->clt[cs].name_of_team);
  xsend(env->cs_graphic, tmp, strlen(tmp), "OKJDF");
}

void		affinfo(t_env *env, int cs, int j)
{
  env->clt[j].nbclient--;
  env->clt[cs].inteam = 1;
  env->clt[cs].num_team = j;
  strcpy(env->clt[cs].name_of_team, env->clt[j].name_of_team);
  memset(env->clt[cs].buf_write, '\0', strlen(env->clt[cs].buf_write));
  sprintf(env->clt[cs].buf_write, "%i\n%i %i\n",  env->clt[j].num_client, env->xwidth,
	  env->ylength);
  xsend(cs, env->clt[cs].buf_write, strlen(env->clt[cs].buf_write), "info");
  initcordonneeclter(env, cs);
  memset(env->clt[cs].buf_read, '\0', strlen(env->clt[cs].buf_read));
}

void		checkteam(t_env *env, int cs)
{
  int		j;

  j = 1;
  while (j <= env->nb_team)
    {
      if ((strncmp(env->clt[cs].buf_read, env->clt[j].name_of_team,
		   strlen(env->clt[j].name_of_team)) == 0)
	  && (env->clt[cs].inteam != 1))
	{
	  if (env->clt[cs].num_client_egg != 0)
	    init_egg(env, cs);
	  else if (env->clt[j].nbclient == 0)
	    {
	      xsend(cs, "this team is full\n", 19, "full");
	      init_client(&env->clt[cs]);
	      close(cs);
	    }
	  else
	    affinfo(env, cs, j);
	}
      j++;
    }
  if (env->clt[cs].inteam != 1)
    clean_client(env, cs);
  puts("Here comes a new challenger");
}
