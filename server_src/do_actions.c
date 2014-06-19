/*
** do_actions.c for zappy in /Users/vacqui_k/Zappy/zappy-2016-asvine_p/server
**
** Made by kevin vacquier
** Login   <vacqui_k@epitech.eu>
**
** Started on  Tue Jul  2 13:38:31 2013 kevin vacquier
** Last update Wed Jul 10 12:05:52 2013 kevin vacquier
*/

#include "zappy.h"

typedef struct		s_do_act
{
  t_action		action;
  void			(*fct)(t_env *env, int cs);
}			t_do_act;

static t_do_act		do_act_map[13] =
  {
    {inactive, NULL},
    {avance, do_avance},
    {droite, do_droite},
    {gauche, do_gauche},
    {voir, do_voir},
    {inventaire, do_inventaire},
    {prendre, do_prendre},
    {pose, do_pose},
    {expulse, do_expulse},
    {broadcast, do_broadcast},
    {incantation, do_incantation},
    {egg, do_egg},
    {connect_nbr, do_connect_nbr}
  };

void			do_actions(t_env *env)
{
  unsigned int		pos;

  pos = 1;
  while (pos <= env->nfds)
    {
      if (env->clt[pos].inteam > 0)
	  if (env->clt[pos].timer <= 0 &&
	      env->clt[pos].act_list[0].action != inactive)
	    {
	      do_act_map[env->clt[pos].act_list[0].action].fct(env, pos);
	      pull_in_act_list(&env->clt[pos]);
	      if (env->clt[pos].act_list[0].action == incantation)
		start_incantation(env, pos);
	      if (env->clt[pos].act_list[0].action == egg)
		start_egg(env, pos);
	    }
      pos++;
    }
}
