/*
** clean_fd.c for zappy.c in /Users/vacqui_k/Zappy/server
**
** Made by kevin vacquier
** Login   <vacqui_k@epitech.eu>
**
** Started on  Sun Jun  2 14:00:38 2013 kevin vacquier
** Last update Thu Jun  6 22:59:51 2013 kevin vacquier
*/

#include "zappy.h"

void	clean_fd(t_client *client)
{
  client->type = FD_FREE;
  client->fct_read = NULL;
  client->fct_write = NULL;
  memset(client->buf_write, '\0', BUF_SIZE);
  memset(client->buf_read, '\0', BUF_SIZE);
}

