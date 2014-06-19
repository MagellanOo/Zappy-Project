//
// Texture.cpp for Texture in /home/asvine_p//Projets/Tek2/Zappy/sfml
// 
// Made by pritesh asvinetsakou
// Login   <asvine_p@epitech.net>
// 
// Started on  Sun Jul 14 18:20:10 2013 pritesh asvinetsakou
// Last update Sun Jul 14 18:28:56 2013 pritesh asvinetsakou
//

#include "Textur.hh"
#include <iostream>

Textur::Textur()
{


}

Textur::~Textur()
{

}

void		Textur::load()
{
  if (!this->_texture.loadFromFile("./Image/Case.png")) // Si le chargement a échoué                       
    {
      std::cout << "Erreur durant le chargement de l'image" << std::endl;
      return; // On ferme le programme                                                                
    }
  else // Si le chargement de l'image a réussi                                                        
    {
      _texture.setSmooth(true);
      _texture.setRepeated(true);
      _sprite.setTexture(_texture);
    }
}
