/*
** prendre.c for zappy.c in /Users/vacqui_k/Zappy/zappy-2016-asvine_p/server
**
** Made by kevin vacquier
** Login   <vacqui_k@epitech.eu>
**
** Started on  Sun Jun 30 12:56:41 2013 kevin vacquier
** Last update Fri Jul 12 19:42:20 2013 KÃ©vin VACQUIER
*/

#include "zappy.h"

static char		*prd[12] =
  {
    "linemate", "deraumere", "sibur", "mendiane",
    "phiras", "thystame", "nourriture"
  };

void			add_prendre(t_env *env, int cs)
{
  put_in_arg_list(&env->clt[cs], prendre, env->clt[cs].buf_read);
}

static void			prendre_send(t_env *env, int cs)
{
  int			len;

  len = strlen(env->clt[cs].buf_write);
  xsend(env->cs_graphic, env->clt[cs].buf_write, len, "prendre");
}

void			do_prendre_2(t_env *env, int cs, int ress, int *pr)
{
  int			x;
  int			y;
  unsigned short	*mr;

  x = env->clt[cs].posx;
  y = env->clt[cs].posy;
  if (env->map[x][y].n_ress[ress] > 0)
    {
      env->map[x][y].n_ress[ress] -= 1;
      env->clt[cs].bag[ress] += 1;
      mr = env->map[x][y].n_ress;
      sprintf(env->clt[cs].buf_write, "pgt %i %i\n",
	      env->clt[cs].num_client, ress);
      prendre_send(env, cs);
      sprintf(env->clt[cs].buf_write, "pin %i %i %i %i %i %i %i %i %i %i\n",
	      env->clt[cs].num_client, x, y, pr[6], pr[0], pr[1], pr[2], pr[3], pr[4],
	      pr[5]);
      prendre_send(env, cs);
      sprintf(env->clt[cs].buf_write, "bct %i %i %i %i %i %i %i %i %i\n", x, y,
	      mr[6], mr[0], mr[1], mr[2], mr[3], mr[4], mr[5]);
      prendre_send(env, cs);
      xsend(cs, "ok\n", 3, "prendre");
    }
  else
    xsend(cs, "ko\n", 3, "prendre");
}


void			do_prendre(t_env *env, int cs)
{
  char			*arg;
  int			i;

  i = 0;
  arg = env->clt[cs].act_list[0].arg;
  puts(arg);
  arg += strlen("prendre ");
  puts(arg);
  while (i < 7 && strncmp(arg, prd[i], strlen(prd[i])))
      i++;
  if (i == 7)
    xsend(cs, "ko\n", 3, "prendre");
  else
    do_prendre_2(env, cs, i, env->clt[cs].bag);
  env = NULL;
}
