/*
** voir_fnct.c for voir in /Users/vacqui_k/Zappy/zappy-2016-asvine_p/server
**
** Made by kevin vacquier
** Login   <vacqui_k@epitech.eu>
**
** Started on  Sun Jul  7 20:58:38 2013 kevin vacquier
** Last update Wed Jul 10 11:11:44 2013 kevin vacquier
*/

#include "zappy.h"

void		voir_1(t_env *env, int cs)
{
  unsigned int	i;
  int		xdep;

  memset(env->clt[cs].buf_write, 0, strlen(env->clt[cs].buf_write));
  strcat(env->clt[cs].buf_write, "{");
  cat_case(env, cs, env->clt[cs].posx, env->clt[cs].posy);
  i = 1;
  while (i <= env->clt[cs].level)
    {
      xdep = env->clt[cs].posx - i;
      while (xdep <= (int)(env->clt[cs].posx + i))
	{
	  cat_case(env, cs, calc_x(env, cs, xdep), calc_y(env, cs, env->clt[cs].posy - i));
	  xdep++;
	}
      i++;
    }
  strcat(env->clt[cs].buf_write, "}\n");
  xsend(cs ,env->clt[cs].buf_write, strlen(env->clt[cs].buf_write), "voir:");
}

void		voir_3(t_env *env, int cs)
{
  unsigned int	i;
  int		xdep;

  puts("voir3");
  memset(env->clt[cs].buf_write, 0, strlen(env->clt[cs].buf_write));
  strcat(env->clt[cs].buf_write, "{");
  cat_case(env, cs, env->clt[cs].posx, env->clt[cs].posy);
  i = 1;
  while (i <= env->clt[cs].level)
    {
      xdep = env->clt[cs].posx + i;
      while (xdep >= (int)(env->clt[cs].posx - i))
	{
	  cat_case(env, cs, calc_x(env, cs, xdep), calc_y(env, cs, env->clt[cs].posy + i));
	  xdep--;
	}
      i++;
    }
  strcat(env->clt[cs].buf_write, "}\n");
  xsend(cs ,env->clt[cs].buf_write, strlen(env->clt[cs].buf_write), "voir:");
}

void		voir_2(t_env *env, int cs)
{
  unsigned int	i;
  int		ydep;

  puts("voir2");
  memset(env->clt[cs].buf_write, 0, strlen(env->clt[cs].buf_write));
  strcat(env->clt[cs].buf_write, "{");
  cat_case(env, cs, env->clt[cs].posx, env->clt[cs].posy);
  i = 1;
  while (i <= env->clt[cs].level)
    {
      ydep = env->clt[cs].posy + i;
      while (ydep >= (int)(env->clt[cs].posy + i))
	{
	  cat_case(env, cs, calc_x(env, cs, env->clt[cs].posx + i), calc_y(env, cs, ydep));
	  ydep--;
	}
      i++;
    }
  strcat(env->clt[cs].buf_write, "}\n");
  xsend(cs ,env->clt[cs].buf_write, strlen(env->clt[cs].buf_write), "voir:");
}

void		voir_0(t_env *env, int cs)
{
  unsigned int	i;
  int		ydep;

  puts("voir0");
  memset(env->clt[cs].buf_write, 0, strlen(env->clt[cs].buf_write));
  strcat(env->clt[cs].buf_write, "{");
  cat_case(env, cs, env->clt[cs].posx, env->clt[cs].posy);
  i = 1;
  while (i <= env->clt[cs].level)
    {
      ydep = env->clt[cs].posy - i;
      while (ydep <= (int)(env->clt[cs].posy + i))
	{
	  cat_case(env, cs, calc_x(env, cs, env->clt[cs].posx - i), calc_y(env, cs, ydep));
	  ydep++;
	}
      i++;
    }
  strcat(env->clt[cs].buf_write, "}\n");
  xsend(cs ,env->clt[cs].buf_write, strlen(env->clt[cs].buf_write), "voir:");
}
