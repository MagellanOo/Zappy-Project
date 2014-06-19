// Case.cpp for Case in /home/asvine_p//Projets/Tek2/Zappy/sfml
// 
// Made by pritesh asvinetsakou
// Login   <asvine_p@epitech.net>
// 
// Started on  Thu Jul 11 20:05:22 2013 pritesh asvinetsakou
// Last update Sun Jul 14 18:38:22 2013 pritesh asvinetsakou
//

#include "Case.hh"

Case::Case(int _x, int _y, sf::Texture *texture)
{
  this->x = _x;
  this->y = _y;
  my_texture = texture;
}

Case::~Case()
{


}

void                    Case::initialize()
{
  my_sprite.setTexture(*my_texture);
}


void			Case::draw_map(sf::RenderWindow &window)
{
  my_sprite.setTextureRect(sf::IntRect(112, 0, 202, 152));
  my_sprite.setPosition((this->x * 200), (this->y * 150));
  window.draw(this->my_sprite);
}

void			Case::draw_res(sf::RenderWindow &window)
{
  if (nourriture > 1)
    {
      my_sprite.setTextureRect(sf::IntRect((0 * 16), 0, 16, 16));
      this->my_sprite.setPosition((this->x * 200), (this->y * 150));
      window.draw(this->my_sprite);
    }
 if (linemate > 1)
    {
      my_sprite.setTextureRect(sf::IntRect(16, 0, 16, 16));
      this->my_sprite.setPosition((this->x * 200) + 30, (this->y * 150) + 20);
      window.draw(this->my_sprite);
    }
 if (deraumere > 1)
    {
      my_sprite.setTextureRect(sf::IntRect((2 * 16), 0, 16, 16));
      this->my_sprite.setPosition((this->x * 200) + (2 * 30), (this->y * 150) + (2 * 20));
      window.draw(this->my_sprite);
    }
 if (sibur > 1)
    {
      my_sprite.setTextureRect(sf::IntRect((3 * 16), 0, 16, 16));
      this->my_sprite.setPosition((this->x * 200) + (3 * 30), (this->y * 150) + (3 * 20));
      window.draw(this->my_sprite);
    }
 if (mendiane > 1)
    {
      my_sprite.setTextureRect(sf::IntRect((4 * 16), 0, 16, 16));
      this->my_sprite.setPosition((this->x * 200) + (4 * 30), (this->y * 150) + (4 * 20));
      window.draw(this->my_sprite);
    }
 if (phiras > 1)
    {
      my_sprite.setTextureRect(sf::IntRect((5 * 16), 0, 16, 16));
      this->my_sprite.setPosition((this->x * 200) + (5 * 30), (this->y * 150) + (5 * 20));
      window.draw(this->my_sprite);
    }
 if (thystame > 1)
    {
      my_sprite.setTextureRect(sf::IntRect((6 * 16), 0, 16, 16));
      this->my_sprite.setPosition((this->x * 200) + (6 * 30), (this->y * 150) + (6 * 20));
      window.draw(this->my_sprite);
    }
}

void			Case::setMysprite(sf::Sprite _my_sprite)
{
  this->my_sprite = _my_sprite;
}

sf::Sprite		&Case::getMysprite()
{
  return(this->my_sprite);
}

void		Case::set_linemate(int _linemate)
{
  this->linemate = _linemate;
}

void		Case::set_sibur(int _sibur)
{
  this->sibur = _sibur;
}

void		Case::set_deraumere(int _deraumere)
{
  this->deraumere = _deraumere;
}

void		Case::set_mendiane(int _mendiane)
{
  this->mendiane = _mendiane;
}

void		Case::set_phiras(int _phiras)
{
  this->phiras = _phiras;
}

void		Case::set_thystame(int _thystame)
{
  this->thystame = _thystame;
}

void		Case::set_nourriture(int _nourriture)
{
  this->nourriture = _nourriture;
}


int		Case::get_linemate()
{
  return(this->linemate);
}

int		Case::get_sibur()
{
  return(this->sibur);
}

int		Case::get_deraumere()
{
  return(this->deraumere);
}

int		Case::get_mendiane()
{
  return(this->mendiane);
}

int		Case::get_phiras()
{
  return(this->phiras);
}

int		Case::get_thystame()
{
  return(this->thystame);
}

int		Case::get_nourriture()
{
  return(this->nourriture);
}
