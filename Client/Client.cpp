
//
// Client.cpp for  in /home/el-hai_a//zappy-2015-2014s-trebuc_f/Client
// 
// Made by anice el-haitari
// Login   <el-hai_a@epitech.net>
// 
// Started on  Sun Jul  7 01:10:17 2013 anice el-haitari
// Last update Sun Jul 14 19:46:27 2013 pritesh asvinetsakou
//

#include <iostream>
#include "Client.hh"
#include "Game.hh"



void client::do_client(int cs)
{
  send(cs, "GRAPHIC\n", strlen("GRAPHIC\n"), MSG_NOSIGNAL);
}

char *client::recup_info(int cs)
{
  fd_set read_fds;
  struct timeval timeout;

  memset(buf_read, '\0', BUF_SIZE);
  bzero(buf_read, BUF_SIZE);
  timeout.tv_sec = 1;
  timeout.tv_usec = 0;
  FD_ZERO(&read_fds);
  FD_SET(cs, &read_fds);
  select(cs + 1, &read_fds, NULL, NULL, &timeout);
  if(FD_ISSET(cs, &read_fds))
    {
      bzero(buf_read, BUF_SIZE);
      recv(cs, buf_read, BUF_SIZE, 0);
      std::cout << buf_read << std::endl;
    }
  return(buf_read);
}


client::client(int ac, char **av)
{  
  char buf[1024];
  struct sockaddr_in		sin;
  Game                          game;

  sin = sin;
  port = atoi(av[1]);
  pe = getprotobyname("TCP");
  s = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (s == -1)
    {
      write(2, "socket", strlen("socket"));
      exit(EXIT_FAILURE);
    }
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = inet_addr(av[2]);
  error = connect(s, (const struct sockaddr *)&sin, sizeof(sin));

  if (error == -1)
    {
      write(2, "connect", strlen("connect"));
      close(s);
      exit(EXIT_FAILURE);
    }
  std::cout << "ok" << std::endl;
  do_client(s);

  game.set_cmp(recup_info(s));
  game.set_cmp(recup_info(s));
  while(game.getMywindow().isOpen())
    {
      if (game.get_cmp() != NULL)
	{
	  game.pars();
	  game.getMywindow().clear();
	  game.getMywindow().display();
	}
      game.update();	
      game.draw();
	  
      std::cout << "end" << std::endl;
      //      return;
    }
}

client::~client()
{

}

int	main(int ac, char **av)
{
  if (ac == 3)
    client(ac, av);
  else
    std::cout << "USE: ./client [port] [adress]" << std::endl;
  return (0);
}
