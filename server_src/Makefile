##
## Makefile for Zappy in /Users/vacqui_k/Zappy/server
## 
## Made by kevin vacquier
## Login   <vacqui_k@epitech.eu>
## 
## Started on  Tue Jun  4 11:21:26 2013 kevin vacquier
## Last update Sun Jul 14 20:26:12 2013 pritesh asvinetsakou
##

NAME	= server

OBJDIR	= obj/

SRC	= get_opt_fnct.c \
	  get_opt.c \
	  init_env.c \
	  start_actions.c \
	  count_player_case.c \
	  xfunct.c \
	  srv_create.c \
	  clean_fd.c \
	  gen_ress.c \
	  init_fds.c \
	  avance.c \
	  egg.c \
	  act_list.c \
	  client_read.c \
	  checkcmd.c \
	  connect_nbr.c \
	  droite.c \
	  gauche.c \
	  incantation.c \
	  init_graph.c \
	  inventaire.c \
	  sendof.c \
	  voir.c \
	  voir_fnct.c \
	  expulse.c \
	  pose.c \
	  prendre.c \
	  broadcast.c \
	  checkteam.c \
	  apply_timers.c \
	  do_actions.c \
	  main.c

LIB	= -lm
INC	=

OBJ	= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJDIR), $(OBJ))
CC	= gcc
CFLAGS	= -W -Werror -Wall
CDEBUG	= -W -Wall -ansi -pedantic -g -ggdb
RM	= rm -f
ECHO	= echo

$(NAME)	: $(OBJ)
	@$(ECHO) '\n-----Compiling-----\n'
	$(CC) $(INC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB)
	@$(ECHO) '\n-----Compiled-----\n'

clang	: $(OBJ)
	clang $(INC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB)
	$(ECHO) 'Compiled'


clean	:
	-@$(RM) $(OBJ)
	-@$(RM) *~
	-@$(RM) #*#
	@$(ECHO) 'Directory cleaned'

all	: $(NAME)

fclean	: clean
	-@$(RM) $(NAME)
	@$(ECHO) 'Remove executable'

re	: fclean all

.PHONY	: all clean re

debug	: $(OBJ)
	@$(CC) $(INC) $(CDEBUG) -o $(NAME) $(OBJDIR)/$(OBJ) $(LIB)
	@$(ECHO) '\033[0;32m> Mode Debug: done\033[0m'

.c.o	: 
	$(CC) $(INC) $(CFLAGS) -o $(OBJDIR)/$@ -c $<
