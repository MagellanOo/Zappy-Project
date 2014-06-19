//
// Object.cpp for Object in /home/asvine_p//Projets/Tek2/Zappy/sfml
// 
// Made by pritesh asvinetsakou
// Login   <asvine_p@epitech.net>
// 
// Started on  Sun Jul  7 16:45:17 2013 pritesh asvinetsakou
// Last update Thu Jul 11 13:28:44 2013 pritesh asvinetsakou
//

#include "Object.hh"

Object::Object() : my_window(sf::VideoMode(1920, 1080), "Zappy Bibicy")
{
  // my_view.rotate();
  map_view.setViewport(sf::FloatRect(0.25f, 0.f, 0.5f, 0.75));
  my_window.setView(map_view);
}

Object::~Object()
{

}

void			Object::update()
{
  while (my_window.pollEvent(this->clavier))
    {
      // Fenêtre fermée                                                    
      if (this->clavier.type == sf::Event::Closed)
        my_window.close();
      // Touche 'echap' appuyée                                                                       
      if (this->clavier.type == sf::Event::KeyPressed)
        {
          if (this->clavier.key.code == sf::Keyboard::Escape)
            my_window.close();
          if (this->clavier.key.code == sf::Keyboard::Left)
            {
              this->map_view.move(-25, 0);
              this->my_window.setView(this->map_view);
            }
          if (this->clavier.key.code == sf::Keyboard::Right)
            {
              this->map_view.move(25, 0);
              this->my_window.setView(this->map_view);
            }
          if (this->clavier.key.code == sf::Keyboard::Up)
            {
              this->map_view.move(0, -25);
              this->my_window.setView(this->map_view);
            }
          if (this->clavier.key.code == sf::Keyboard::Down)
            {
              map_view.move(0, 25);
              this->my_window.setView(this->map_view);
            }
          if (this->clavier.key.code == sf::Keyboard::S)
            {
              map_view.zoom(0.5f);
              this->my_window.setView(this->map_view);
            }
          if (this->clavier.key.code == sf::Keyboard::X)
            {
              map_view.zoom(1.5f);
              this->my_window.setView(this->map_view);
            }
        }
    }
}


sf::RenderWindow	&Object::getMywindow()
{
  return(this->my_window);
}
