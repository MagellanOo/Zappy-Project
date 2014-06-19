/*
** zappy.h for ZAPPY in /Users/vacqui_k/Zappy/server
**
** Made by kevin vacquier
** Login   <vacqui_k@epitech.eu>
**
** Started on  Sat Jun  1 23:01:15 2013 kevin vacquier
** Last update Fri Jul 12 20:01:47 2013 KÃ©vin VACQUIER
*/

#ifndef		__KEW_ZAPPY_H__
#define		__KEW_ZAPPY_H__

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/resource.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>
#include <signal.h>

#define INIT_LVL       	1
#define INIT_TIME	1260
#define BUF_SIZE	4096
#define MAXCLIENT	500
#define INIT_RESSOURCE	500
#define FD_FREE		0
#define FD_SRV		1
#define FD_CLIENT      	2
#define FD_GRAPH      	3
#define OPT_MAX_CLIENT	"ERROR : To many client per team\n"
#define USAGE		"USAGE : %s -p 'port' -x 'largeur' -y 'hauteur' -n 'Nom des équipes' -c 'Nb de client par equipe' -t 'Unité de temps'\n"
#define MAX(a,b)	((a > b) ? a : b)
#define MIN(a,b)	((a < b) ? a : b)
#define DIR(a)		((a == 0) ? 4 : a)

typedef enum		e_state
  {
    alive,
    dead,
    inegg
  }			t_state;

typedef enum		e_ativity
  {
    begin,
    found
  }			t_activity;

typedef enum		e_action
  {
    inactive,
    avance,
    droite,
    gauche,
    voir,
    inventaire,
    prendre,
    pose,
    expulse,
    broadcast,
    incantation,
    egg,
    connect_nbr
  }			t_action;

typedef enum		e_ressources
  {
    linemate,
    deraumere,
    sibur,
    mendiane,
    phiras,
    thystame,
    food
  }			t_ressources;

typedef struct		s_case
{
  unsigned short       	n_ress[7];
}			t_case;

typedef struct		s_act
{
  t_action		action;
  char			*arg;
}			t_act;

typedef struct		s_client
{
  unsigned int		g;
  int			type;
  void			(*fct_read)();
  void			(*fct_write)();
  char			name_of_team[9];
  char			localhost[9];
  char			buf_read[BUF_SIZE];
  char			buf_write[BUF_SIZE];
  unsigned int		fd;
  unsigned int		nbclient;
  unsigned int		posx;
  unsigned int		posy;
  unsigned int		posxegg;
  unsigned int		posyegg;
  unsigned int		level;
  unsigned int		vision;
  t_act			act_list[10];
  t_activity		activity;
  t_state		state;
  unsigned int 		inteam;
  unsigned int		num_team;
  float			timer;
  float			eat_timer;
  int			bag[7];
  unsigned int		dir;
  unsigned int		num_client;
  unsigned int		num_client_egg;
  unsigned int		maxclient;
}			t_client;

typedef struct		s_env
{
  t_case		**map;
  unsigned int		maxfd;
  unsigned int		clt_max;
  unsigned int		clt_min;
  int			r;
  fd_set		fd_read;
  fd_set		fd_write;
  unsigned int		port;
  unsigned int		xwidth;
  unsigned int		ylength;
  unsigned int		nb_client;
  unsigned int		nb_client_tot;
  unsigned int		ac;
  t_client		*clt;
  float			timeunity;
  int			nb_co;
  unsigned int		cs_graphic;
  int			sockfd;
  int			cs;
  unsigned int		nfds;
  int			nb_team;
  unsigned int	       	csinlen;
  unsigned int		first;
  unsigned int		tot_res;
  short			lvls[8];
  unsigned int		numegg;
  float			elapsed_time;
  int			in_action;
  struct sockaddr_in	sin;
  struct sockaddr_in	csin;
}			t_env;


/*
** main.c
*/

int	main(int ac, char **av);


/*
** xfunct.c
*/

void	calc_total_by_level(t_env *e);
void	*xmalloc(size_t size);
void	xwrite(int fildes, const void *buf, size_t nbyte);
void	xsend(int cs, char *buf, int strlenbuf, char *fct);
void	write_eof(int fd);

/*
** clean_fd.c
*/

void	clean_fd(t_client *client);

/*
** init_env.c
*/

void	init_env_lvls(t_env *env);
void	init_env_srv(t_env *env);
void	init_client(t_client *client);
void	init_env(t_env *env);

/*
** init_fds.c
*/

void	init_fds(t_env *env);

/*
** get_opt.c
*/

int	getport(t_env *env, char ** av, int i);
void	get_opt(t_env *env, int ac, char **av);

/*
** get_opt_fnct.c
*/

int	gettime(t_env *env, char **av, int i);
int	getteam(t_env *env, char **av, int i);
int	getlimteam(t_env *env, char **av, int i);
int	getx(t_env *env, char **av, int i);
int	gety(t_env *env, char **av, int i);

/*
** srv_create.c
*/

void	srv_accept(t_env *env);
void	srv_create(t_env *env);

/*
** gen_ress.c
*/

void	gen_ress(t_env *env);

/*
** act_list.c
*/

void	init_act_list(t_client *client);
void	put_in_arg_list(t_client *client, t_action action, char *arg);
void	pull_in_act_list(t_client *client);

/*
**  checkcmd.c
*/

void  	checkcmd(t_env *env, int cs);

/*
** voir.c
*/

void   	add_voir(t_env *env, int cs);
void   	do_voir(t_env *env, int cs);
int	calc_x(t_env *env, int cs, int x);
int	calc_y(t_env *env, int cs, int y);
void	cat_case(t_env *env, int cs, int x, int y);

/*
** voir_fnct.c
*/

void		voir_0(t_env *env, int cs);
void		voir_1(t_env *env, int cs);
void		voir_2(t_env *env, int cs);
void		voir_3(t_env *env, int cs);


/*
** sendof.c
*/

void	sendof(t_env *env, int cs);


/*
** inventaire.c
*/

void   	add_inventaire(t_env *env, int cs);
void   	do_inventaire(t_env *env, int cs);

/*
** init_graph.c
*/

void	send_map(t_env *env);
void	send_players(t_env *env);
void	send_player_level(t_env *env, int cs);
void	init_graph(t_env *env, int cs);

/*
** incantation.c
*/

void   	add_incantation(t_env *env, int cs);
void   	do_incantation(t_env *env, int cs);

/*
** gauche.c
*/

void   	add_gauche(t_env *env, int cs);
void   	do_gauche(t_env *env, int cs);

/*
** droite.c
*/

void   	add_droite(t_env *env, int cs);
void   	do_droite(t_env *env, int cs);

/*
** expulse.c
*/

void   	add_expulse(t_env *env, int cs);
void   	do_expulse(t_env *env, int cs);

/*
** egg.c
*/

void	clean_egg(t_env *env,int cs);
void   	add_egg(t_env *env, int cs);
void   	do_egg(t_env *env, int cs);
void   	init_egg(t_env *env, int cs);

/*
** egg.c
*/

void   	add_egg(t_env *env, int cs);
void   	do_egg(t_env *env, int cs);

/*
** avance.c
*/

void   	add_avance(t_env *env, int cs);
void   	do_avance(t_env *env, int cs);

/*
** pose.c
*/

void   	add_pose(t_env *env, int cs);
void   	do_pose(t_env *env, int cs);

/*
** prendre.c
*/

void   	add_prendre(t_env *env, int cs);
void   	do_prendre(t_env *env, int cs);

/*
** broadcast.c
*/

void   	add_broadcast(t_env *env, int cs);
unsigned int	broadcast_dir(int dest, int cs, t_env *env);
void		send_broadcast(int dest, int cs, t_env *env, int dir);
void   	do_broadcast(t_env *env, int cs);

/*
** connect_nbr.c
*/

void   	add_connect_nbr(t_env *env, int cs);
void   	do_connect_nbr(t_env *env, int cs);

/*
** client_read.c
*/

void	clean_client(t_env *env, int cs);
void	client_read(t_env *env, int cs);

/*
** client_read.c
*/

void	verifonecase(t_env *env, int cs);
void	verifeachcase(t_env *env);
void	initcordonneeclter(t_env *env, int cs);
void	affinfo(t_env *env, int cs, int j);
void	checkteam(t_env *env, int cs);

/*
** apply_timers.c
*/

void	apply_timers(t_env *env);
void	apply_timer_player(t_env *env, int cs);
void	apply_timer_egg(t_env *env, int cs);
void	apply_timer_rot(t_env *env, int cs);

/*
** count_player_case.c
*/

int    	count_player_case(t_env *env, int cs);
int    	see_player_case(t_env *env, int cs, int x, int y);

/*
** do_actions.c
*/

void	do_actions(t_env *env);

/*
** start_actions.c
*/

void	start_incantation(t_env *env, int cs);
void	start_egg(t_env *env, int cs);

/*
** clean_env.c
*/

void		clean_game(t_env *env);

#endif /* !__KEW_ZAPPY_H__ */
