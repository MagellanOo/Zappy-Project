##                                                                                                    
## Makefile for Makefile in /home/magal_g/Dropbox/Zappy (1)/magal_g                                   
##                                                                                                    
## Made by gaetan magal                                                                               
## Login   <magal_g@epitech.net>                                                                      
##                                                                                                    
## Started on  Thu Jun 19 17:28:09 2014 gaetan magal                                                  
## Last update Thu Jun 19 18:00:13 2014 gaetan magal                                                  
##                                                                                                    

NAME1   = zappy_server
NAME2   = client_graphique

DIR1    = server_src
DIR2    = Client

SOURCES = Clientv2/main.cpp

OBJ     = $(SRC:.c=.o)
CC      = /usr/bin/gcc
CFLAGS  = -W -Werror -Wall -g
CDEBUG  = -W -Wall -ansi -pedantic -g -ggdb
RM      = rm -f

#ECHO   = echo -e                                                                                     

all     : $(NAME1) $(NAME2)

me :
        g++ $(CFLAGS) $(SOURCES)


$(NAME1):
        make -C $(DIR1)
        cp $(DIR1)/server ./$(NAME1)

$(NAME2):
        make -C $(DIR2)
        cp $(DIR2)/client_graphique ./$(NAME2)

clean   :
        make -C $(DIR1) clean
        make -C $(DIR2) clean

fclean  : clean
        rm -Rf $(NAME1) $(NAME2)
        make -C $(DIR1) fclean
        make -C $(DIR2) fclean

re      : fclean all
