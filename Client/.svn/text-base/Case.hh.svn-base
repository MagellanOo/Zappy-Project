//
// Case.hh for Case in /home/asvine_p//Projets/Tek2/Zappy/sfml
// 
// Made by pritesh asvinetsakou
// Login   <asvine_p@epitech.net>
// 
// Started on  Thu Jul 11 20:05:44 2013 pritesh asvinetsakou
// Last update Sun Jul 14 18:39:45 2013 pritesh asvinetsakou
//

#ifndef			__CASE_HH__
#define			__CASE_HH__

#include "Game.hh"

class Case
{
  int				x;
  int				y;
  int				linemate;
  int				sibur;
  int				deraumere;
  int				mendiane;
  int				phiras;
  int				thystame;
  int				nourriture;
  sf::Texture			*my_texture;
  sf::Sprite			my_sprite;
  //sf::Texture		my_texture;

public:
  Case(int, int, sf::Texture *);
  ~Case();
  int			get_linemate();
  int			get_sibur();
  int			get_deraumere();
  int			get_mendiane();
  int			get_phiras();
  int			get_thystame();
  int			get_nourriture();
  void			set_linemate(int);
  void			set_sibur(int);
  void			set_deraumere(int);
  void			set_mendiane(int);
  void			set_phiras(int);
  void			set_thystame(int);
  void			set_nourriture(int);
  void                  initialize();
  void			draw_map(sf::RenderWindow &);
  void			draw_res(sf::RenderWindow &);
  void                  setMysprite(sf::Sprite);
  sf::Sprite            &getMysprite();
};

#endif
