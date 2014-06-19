/*
** checkcmd.c for checkopt in /Users/vacqui_k/Zappy/zappy-2016-asvine_p/server
**
** Made by kevin vacquier
** Login   <vacqui_k@epitech.eu>
**
** Started on  Mon Jun 24 15:49:20 2013 kevin vacquier
** Last update Wed Jul 10 12:07:09 2013 kevin vacquier
*/

#include "zappy.h"

typedef struct		s_cmd_c
{
  char			action[24];
  void			(*fct)(t_env *env, int cs);
}			t_cmd_c;

static t_cmd_c		cmd_c[] =
  {
    {"connect_nbr", add_connect_nbr},
    {"avance", add_avance},
    {"droite", add_droite},
    {"gauche", add_gauche},
    {"voir", add_voir},
    {"inventaire", add_inventaire},
    {"pose ", add_pose},
    {"prendre ", add_prendre},
    {"expulse", add_expulse},
    {"broadcast ", add_broadcast},
    {"incantation", add_incantation},
    {"fork", add_egg},
    {"next\n", sendof}
  };

void			checkcmd(t_env *env, int cs)
{
  int			i;
  int			ok;

  i = 0;
  ok = 0;
  while (i < 13 && !ok)
    {
      if (!strncmp(env->clt[cs].buf_read, cmd_c[i].action, strlen(cmd_c[i].action)))
	ok = 1;
      else
	i++;
    }
  if (ok == 1)
    {
      cmd_c[i].fct(env, cs);
      if (env->clt[cs].act_list[0].action == incantation &&
	  env->clt[cs].act_list[1].action == inactive)
	start_incantation(env, cs);
      if (env->clt[cs].act_list[0].action == egg &&
	  env->clt[cs].act_list[1].action == inactive)
	start_egg(env, cs);
    }
}
