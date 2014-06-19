/*
** sendof.c for sendof in /Users/vacqui_k/Zappy/zappy-2016-asvine_p/server
**
** Made by kevin vacquier
** Login   <vacqui_k@epitech.eu>
**
** Started on  Sat Jun 29 19:13:52 2013 kevin vacquier
** Last update Sun Jun 30 13:22:20 2013 kevin vacquier
*/

#include "zappy.h"

void	sendof(t_env *env, int cs)
{
  env = env + 1;
  write_eof(cs);
}
