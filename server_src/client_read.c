/*
** client_read.c for ZAPPHY in /Users/vacqui_k/Zappy/zappy-2016-asvine_p/server
**
** Made by kevin vacquier
** Login   <vacqui_k@epitech.eu>
**
** Started on  Wed Jun 12 13:46:33 2013 kevin vacquier
** Last update Fri Jul 12 16:23:23 2013 KÃ©vin VACQUIER
*/

#include "zappy.h"

void	clean_list(t_client *client)
{
  while (client->act_list[0].action != inactive)
    pull_in_act_list(client);
}

void	clean_client(t_env *env, int cs)
{
  if ((unsigned int)cs == env->cs_graphic)
    env->cs_graphic = 0;
  if (env->clt[cs].num_client != 0)
    {
      printf("pdi %i\n", env->clt[cs].num_client);
      xsend(cs, "mort\n", 5, "mort client");
      if (env->clt[cs].inteam)
	{
	  clean_fd(&env->clt[cs]);
	  clean_list(&env->clt[cs]);
	  env->clt[env->clt[cs].num_team].nbclient++;
	}
      env->nb_co--;
      init_client(&env->clt[cs]);
      printf("client %d gone away\n", cs);
    }
  if (close(cs) == -1)
    perror("close");
}

void	client_read(t_env *env, int cs)
{
  int	r;

  if ((r = recv(cs, env->clt[cs].buf_read, BUF_SIZE, 0)) <= 0)
    perror("recv");
  if ((strncmp(env->clt[cs].buf_read, "quit", 4) == 0) || (r <= 0))
    clean_client(env, cs);
  else
    {
      if (env->cs_graphic == 0 && !strncmp(env->clt[cs].buf_read, "GRAPHIC", 7))
	init_graph(env, cs);
      else if ((env->clt[cs].type == FD_CLIENT) && (cs != (int)env->cs_graphic))
	{
	  (env->clt[cs].inteam == 0) ? (checkteam(env, cs)) : (checkcmd(env, cs));
	  calc_total_by_level(env);
	}
      memset(env->clt[cs].buf_write, '\0', BUF_SIZE);
    }
}
