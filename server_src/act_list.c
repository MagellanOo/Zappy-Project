/*
** act_list.c for zappy in /Users/vacqui_k/Zappy/zappy-2016-asvine_p/server
**
** Made by kevin vacquier
** Login   <vacqui_k@epitech.eu>
**
** Started on  Sat Jun 29 22:29:33 2013 kevin vacquier
** Last update Fri Jul 12 16:06:33 2013 KÃ©vin VACQUIER
*/

#include "zappy.h"

typedef struct	s_time_of_execution
{
  t_action	action;
  float		time;
}		t_time_of_execution;

static t_time_of_execution	cmd_time[12] =
{
  {avance, 7},
  {droite, 7},
  {gauche, 7},
  {prendre, 7},
  {expulse, 7},
  {voir, 7},
  {pose, 7},
  {egg, 42},
  {broadcast, 7},
  {incantation, 300},
  {connect_nbr, 0}
};

void	init_act_list(t_client *client)
{
  int	i;

  i = 0;
  while (i < 10)
    {
      client->act_list[i].action = inactive;
      client->act_list[i].arg = NULL;
      i++;
    }
  client->timer = 0;
}

void	put_in_arg_list(t_client *client, t_action action, char *arg)
{
  int	i;

  i = 0;
  while (client->act_list[i].action != inactive && i < 10)
    i++;
  if (i == 10)
    return;
  client->act_list[i].action = action;
  if (arg)
    client->act_list[i].arg = strdup(arg);
  if (i == 0)
    {
      i = 0;
      while (i < 12 && action != cmd_time[i].action)
	i++;
      if (i == 12)
	i--;
      client->timer = cmd_time[i].time;
    }
}

void	pull_in_act_list(t_client *client)
{
  int	i;

  i = 0;
  if (client->act_list[0].arg != NULL)
    free(client->act_list[0].arg);
  while (i < 9 && client->act_list[i + 1].action != inactive)
    {
      client->act_list[i].action = client->act_list[i + 1].action;
      client->act_list[i].arg = client->act_list[i + 1].arg;
      i++;
    }
  client->act_list[i].action = inactive;
  client->act_list[i].arg = NULL;
  if (client->act_list[i].action != inactive)
    {
      i = 0;
      while (i < 12 && client->act_list[0].action != cmd_time[i].action)
	i++;
      if (i == 12)
	i--;
      client->timer = cmd_time[i].time;
     }
}

