//
// Perso.cpp for perso in /home/asvine_p//Projets/Tek2/Zappy/sfml
// 
// Made by pritesh asvinetsakou
// Login   <asvine_p@epitech.net>
// 
// Started on  Tue Jul  2 16:27:59 2013 pritesh asvinetsakou
// Last update Sun Jul 14 12:34:52 2013 pritesh asvinetsakou
//

#include "Perso.hh"

Perso::Perso(int _x, int _y, int _dir, int _level, int _num)
{
  this->x = _x;
  this->y = _y;
  this->direction = _dir;
  this->level = _level;
  this->num = _num;
}

Perso::~Perso()
{

}

void			Perso::initialize()
{
   if (!this->perso.loadFromFile("./Image/Perso.png")) // Si le chargement a échoué                
    { 
      std::cout << "Erreur durant le chargement de l'image" << std::endl;
      return; // On ferme le programme                                                                
    }
  else // Si le chargement de l'image a réussi                                                        
    {
      nv1.setTexture(perso);
      nv1.setScale(sf::Vector2f(2.f, 2.f));
      //nv1.setSmooth(true);
      // nv1.setRepeated(true);
    }
}


void			Perso::haut()
{
  this->nv1.move(0, -40);
}

void			Perso::bas()
{
 this->nv1.move(0, 40);
}

void			Perso::gauche()
{
 this->nv1.move(-80, 0);
}

void			Perso::droite()
{
 this->nv1.move(80, 0);
}

void			Perso::update(int x, int y, int direction)
{
  nv1.setTextureRect(sf::IntRect(0,(direction * 50) - 50, 40, 40));
  nv1.setPosition((x * 200) + X, (y * 150) + Y);

}

void                    Perso::draw(sf::RenderWindow &window)
{
  update(this->x, this->y, this->direction);
  window.draw(this->nv1);
}

void                    Perso::setMysprite(sf::Sprite _my_sprite)
{
  this->nv1 = _my_sprite;
}

sf::Sprite              &Perso::getMysprite()
{
  return(this->nv1);
}

void                    Perso::setx(int _x)
{
  this->x = _x;
}

void                    Perso::sety(int _y)
{
  this->y = _y;
}

int                     &Perso::getx()
{
  return (this->x);
}

int                     &Perso::gety()
{
  return (this->y);
}

void			Perso::setDirection(int _dir)
{
  this->direction = _dir;
}

int			&Perso::getDirection()
{
  return(this->direction);
}

void			Perso::setNumteam(int _num)
{
  this->team = _num;
}

void			Perso::setLevel(int _level)
{
  this->level = _level;
}

void			Perso::setBroadcast(bool _broadcast)
{
  this->broadcast = _broadcast;
}

void			Perso::setIncentation(bool _incentation)
{
  this->incentation = _incentation;
}

void			Perso::add_inventaire(int *q)
{
  this->bag[0] = q[0]; 
  this->bag[1] = q[1]; 
  this->bag[2] = q[2]; 
  this->bag[3] = q[3]; 
  this->bag[4] = q[4]; 
  this->bag[5] = q[5]; 
  this->bag[6] = q[6]; 
}

void			Perso::setNum(int _num)
{
  this->num = _num;
}

int			&Perso::getNum()
{
  return (this->num);
}
