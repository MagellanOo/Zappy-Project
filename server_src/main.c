/*
** main.c for ZAPPY in /Users/vacqui_k/Zappy/server
**
** Made by kevin vacquier
** Login   <vacqui_k@epitech.eu>
**
** Started on  Sun Jun  2 12:11:26 2013 kevin vacquier
** Last update Tue Jun 10 15:22:52 2014 perez_d
*/

#include "zappy.h"

static int		stop;

void			do_select(t_env *env)
{
  struct timeval	timer;
  float			tmp_float;

  timer.tv_sec = (long int)(1 / env->timeunity);
  tmp_float = (1 / env->timeunity) - timer.tv_sec;
  tmp_float *= 1000000;
  timer.tv_usec = (long int)tmp_float;
  env->r = select(env->nfds + 1, &env->fd_read, NULL, NULL, &timer);
  tmp_float = timer.tv_usec / 100000;
  tmp_float /= 10;
  tmp_float += timer.tv_sec;
  env->elapsed_time = 1 - (tmp_float * env->timeunity);
  if (env->r == -1)
    perror("select");
}

void			check_fds(t_env *env)
{
  unsigned int	       	i;

  i = 0;
  while (i < env->maxfd && env->r > 0)
    {
      if (FD_ISSET(i, &env->fd_read))
	{
	  env->clt[i].fct_read(env, i);
	  env->r -= 1;
	}
      i++;
    }
}

void			stopper()
{
  puts("Hooo, the game was not finished... to bad...");
  stop = 0;
}

void			game(t_env *env)
{
  while (stop == 42)
    {
      init_fds(env);
      do_select(env);
      check_fds(env);
      apply_timers(env);
      do_actions(env);
    }
}

int			main(int ac, char **av)
{
  t_env			env;

  stop = 42;
  puts("HELLO, you've launch the server. please wait");
  signal (SIGQUIT, stopper);
  signal (SIGINT, stopper);
  init_env(&env);
  get_opt(&env, ac, av);
  srv_create(&env);
  gen_ress(&env);
  puts("So, all is good. Let's Go ;)");
  game(&env);
  //  clean_game(&env);
  return (1);
}
