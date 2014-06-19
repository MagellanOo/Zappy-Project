
NAME	=	client_graphique

CXX	=	g++ -g3

RM	=       rm -fv

SRC	=	Game.cpp\
		Case.cpp\
		Parser.cpp\
		Textur.cpp\
		Perso.cpp\
		Client.cpp

OBJS	=	$(SRC:.cpp=.o)

all: 		$(OBJS)
		$(CXX) -o $(NAME) $(OBJS) -lGL -lGLU -lsfml-graphics -lsfml-window -lsfml-system



clean:
		$(RM) $(OBJS) $(NAME)

fclean: 	clean
		$(RM) $(NAME)

re:     	fclean all

.PHONY: clean fclean distclean
