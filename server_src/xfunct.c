/*
** xfunct.c for Zappy in /Users/vacqui_k/Zappy/server
**
** Made by kevin vacquier
** Login   <vacqui_k@epitech.eu>
**
** Started on  Sun Jun  2 14:13:43 2013 kevin vacquier
** Last update Wed Jul 10 10:27:59 2013 kevin vacquier
*/

#include "zappy.h"

void		calc_total_by_level(t_env *e)
{
  unsigned int	i;

  memset(e->lvls, 0, 8);
  i = 0;
  while (i <= e->nfds)
    {
      if (i != e->cs_graphic && e->clt[i].state == alive)
	{
	  e->lvls[e->clt[i].level - 1] += 1;
	}
      i++;
    }
}

void	*xmalloc(size_t size)
{
  void	*ptr;

  ptr = malloc(size);
  if (ptr == NULL)
    {
      puts("MALLOC FATAL ERROR");
      exit(-1);
    }
  return (ptr);
}

void	write_eof(int fd)
{
  char	c;

  c = EOF;
  write(fd, &c, 1);
}

void		xwrite(int fildes, const void *buf, size_t nbyte)
{
  if (write(fildes, buf, nbyte) == -1)
    perror("error write\n");
}

void		xsend(int cs, char *buf, int strlenbuf, char *fct)
{
  if (cs < 3)
    write(cs, buf, strlenbuf);
  else if (send(cs, buf, strlenbuf, 0x2000) == -1)
    {
      perror(fct);
      if (pause() == -1) perror("error Pause");
    }
}
