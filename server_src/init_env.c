/*
** env.c for Zappy in /Users/vacqui_k/Zappy/server
**
** Made by kevin vacquier
** Login   <vacqui_k@epitech.eu>
**
** Started on  Sun Jun  2 12:43:48 2013 kevin vacquier
** Last update Tue Jun 17 14:41:50 2014 perez_d
*/

#include "zappy.h"

void		init_env_lvls(t_env *env)
{
  memset(env->lvls, 0, 8);
  env->in_action = 0;
  env->first = 0;
}

void		init_env_srv(t_env *env)
{
  struct rlimit	rlp;

  env->maxfd = rlp.rlim_cur;
  env->port = 0;
  env->xwidth = 0;
  env->ylength = 0;
  env->timeunity = 100;
  env->nb_client_tot = 0;
  env->nb_client = 0;
  env->nb_team = 1;
  env->nb_co = 0;
  env->numegg = 0;
  env->cs_graphic = 0;
  env->tot_res = 0;
}

void		init_client(t_client *client)
{
  memset(client->name_of_team, '\0', 9);
  memset(client->localhost, '\0', 9);
  client->num_team = -1;
  client->num_client = 0;
  client->fd = 0;
  client->type = FD_FREE;
  client->nbclient = 0;
  client->posx = 0;
  client->posy = 0;
  client->posxegg = 0;
  client->posyegg = 0;
  client->level = INIT_LVL;
  client->dir = rand() % 4;
  client->g = 0;
  client->state = -1;
  client->inteam = 0;
  client->num_client_egg = 0;
  client->timer = 0;
  memset(client->bag, 0, 7);
  clean_fd(client);
  init_act_list(client);
}

void		init_env(t_env *env)
{
  int		client;

  client = 0;
  srand(time(NULL));
  init_env_lvls(env);
  init_env_srv(env);
  env->clt = xmalloc(sizeof(t_client) * (MAXCLIENT + 5));
  env->xwidth = 42;
  env->ylength = 42;
  env->timeunity = 42;
  env->port = 4242;
  while (client < MAXCLIENT + 5)
    {
      init_client(&env->clt[client]);
      client++;
    }
  puts("INFO : 1/4 environement initialized");
}
