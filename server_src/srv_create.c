/*
** srv_create.c for ZAPPY in /Users/vacqui_k/Zappy/server
**
** Made by kevin vacquier
** Login   <vacqui_k@epitech.eu>
**
** Started on  Tue Jun  4 16:25:57 2013 kevin vacquier
** Last update Fri Jul 12 20:05:16 2013 KÃ©vin VACQUIER
*/

#include "zappy.h"

void	srv_accept(t_env *env)
{
  int	cs = 0;

  cs = accept(env->sockfd, (struct sockaddr*)&env->csin, &env->csinlen);
  if (cs == -1)
    perror("Error accept");
  env->clt[cs].type = FD_CLIENT;
  env->clt[cs].state = 0;
  env->clt[cs].timer = INIT_TIME;
  env->clt[cs].fct_read = client_read;
  memset(env->clt[cs].buf_write, '\0', strlen(env->clt[cs].buf_write));
  env->clt[cs].eat_timer = 0;
  env->clt[cs].fd = cs;
  env->clt[cs].inteam = 0;
  env->nfds = MAX(cs, (int)env->nfds);
  env->nb_co++;
  env->clt[cs].num_client = env->nb_co;
  xsend(cs, "BIENVENUE\n", strlen("BIENVENUE\n"), "accept");
}


void			srv_create(t_env *env)
{
  struct protoent	*pe;

  env->cs = 0;
  if ((pe = getprotobyname("TCP")) == NULL)
    exit(EXIT_FAILURE);
  if ((env->sockfd = socket(PF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    perror("socket");
  env->nfds = env->sockfd;
  bzero((char*)&env->sin, sizeof(&env->sin));
  env->sin.sin_family = AF_INET;
  env->sin.sin_addr.s_addr = INADDR_ANY;
  env->sin.sin_port = htons(env->port);
  if ((bind(env->sockfd, (struct sockaddr*)&env->sin, sizeof(env->sin))) == -1)
    {
      perror("bind");
      exit(EXIT_FAILURE);
    }
  if ((listen(env->sockfd, MAXCLIENT)) == -1)
    perror("listen");
  env->clt[env->sockfd].type = FD_SRV;
  env->clt[env->sockfd].fct_read = srv_accept;
  puts("INFO : 3/4 The Connection is OK");
}
