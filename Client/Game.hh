//
// Game.hh for Game in /home/asvine_p//Projets/Tek2/Zappy/sfml
// 
// Made by pritesh asvinetsakou
// Login   <asvine_p@epitech.net>
// 
// Started on  Fri Jul 12 12:56:48 2013 pritesh asvinetsakou
// Last update Sun Jul 14 18:37:08 2013 pritesh asvinetsakou
//

#ifndef			__GAME_HH__
#define			__GAME_HH__

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include "Case.hh"
#include "Parser.hh"
#include "Perso.hh"

class Case;

class Game
{
  std::vector< std::vector<Case> > _map;
  std::vector<Perso>			_perso;
  char				*cmp;
  bool				pause;
  int				sizex;
  int				sizey;
  float				time;
  bool				finish;
  std::vector<std::string>	team_name;
  sf::RenderWindow		my_window;
  sf::View			map_view;
  sf::View			g_view;
  sf::Event			clavier;
  sf::Texture			texture;
public:
  Game();
  ~Game();
  void			init_map();
  // inline vector<string> get_teamName const {return this->team_name;}
  void			set_sizex(int);
  void			set_sizey(int);
  void			set_time(float);
  void			set_finish(bool);
  void			set_pause(bool);
  void			set_cmp(char *);
  void			pars();
  void                  update();
  sf::RenderWindow      &getMywindow();
  void			draw();
  void			initialize();
  int			&get_sizex();
  int			&get_sizey();
  char			*get_cmp();
  bool			&get_pause();
  float			&get_time();
  bool			&get_finish();
  void			set_case(int, int, int *);
  void			set_teamName(std::string _name);
  void			add_perso(Perso);
  std::string		m_getline(int &);
};

#endif
