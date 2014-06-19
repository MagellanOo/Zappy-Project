//
// Menu.cpp for menu in /home/asvine_p//Projets/Tek2/Zappy/sfml
// 
// Made by pritesh asvinetsakou
// Login   <asvine_p@epitech.net>
// 
// Started on  Mon Jul  1 17:36:47 2013 pritesh asvinetsakou
// Last update Thu Jul 11 14:16:38 2013 pritesh asvinetsakou
//

#include "Menu.hh"

Map::Menu()
{
  left_view.setViewport(sf::FloatRect(0.25f, 0.f, 0.5f, 0.75));
  my_window.setView(left_view);
}

Map::~Menu()
{

}

void		Menu::initialize()
{
  if (!this->text.loadFromFile("./Image/ressources.png")) // Si le chargement a échoué                
    {
      std::cout << "Erreur durant le chargement de l'image" << std::endl;
      return; // On ferme le programme                                                                
    }
  else // Si le chargement de l'image a réussi                                                        
    menu.setTexture(text);
}


void		Menu::update()
{

}

void		Map::draw()
{

}
