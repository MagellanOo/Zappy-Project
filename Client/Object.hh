//
// Object.hh for Object in /home/asvine_p//Projets/Tek2/Zappy/sfml
// 
// Made by pritesh asvinetsakou
// Login   <asvine_p@epitech.net>
// 
// Started on  Sun Jul  7 16:29:21 2013 pritesh asvinetsakou
// Last update Thu Jul 11 14:14:19 2013 pritesh asvinetsakou
//

#ifndef         __OBJECT_HH__
#define         __OBJECT_HH__

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>

class	Object
{
public:
  Object();
  ~Object();
  void			update();
  sf::RenderWindow	&getMywindow();  
protected:
  sf::RenderWindow	my_window;
  sf::View              map_view;
  sf::View		g_view;
  sf::Event		clavier;
};

#endif
