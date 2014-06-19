//
// client.hh for  in /home/el-hai_a//zappy-2015-2014s-trebuc_f/Client
// 
// Made by anice el-haitari
// Login   <el-hai_a@epitech.net>
// 
// Started on  Sun Jul  7 00:59:24 2013 anice el-haitari
// Last update Sun Jul 14 19:40:10 2013 pritesh asvinetsakou
//

#ifndef		__CLIENT_HH__
#define		__CLIENT_HH__

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>
#include <cstdlib>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>

#define BUF_SIZE        4096


class	client
{
public:
  struct protoent	*pe;
  struct sockaddr_in	sin;
  int			s;
  int			port;
  int			error;
  char			*str;
  int			cs;
  char			buf_read[];
  client(int ac, char **av);
  void do_client(int cs);
  ~client();
  char *recup_info(int cs);
};


#endif
