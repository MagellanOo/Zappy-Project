//
// Menu.hh for Menu in /home/asvine_p//Projets/Tek2/Zappy/sfml
// 
// Made by pritesh asvinetsakou
// Login   <asvine_p@epitech.net>
// 
// Started on  Sun Jul  7 23:12:22 2013 pritesh asvinetsakou
// Last update Thu Jul 11 14:15:28 2013 pritesh asvinetsakou
//


#ifndef         __MENU_HH__
#define         __MENU_HH__

#include "Object.hh"

class   Menu : public Map
{
public:
  Menu();
  ~Menu();
  void                  initialize();
  void                  update();
  void                  draw();
 protected:
  sf::Sprite		menu;
  sf::View		left_view;
  sf::Texture           text;
};

#endif
