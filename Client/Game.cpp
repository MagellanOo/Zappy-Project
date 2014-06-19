//
// Game.cpp for Game in /home/asvine_p//Projets/Tek2/Zappy/sfml
// 
// Made by pritesh asvinetsakou
// Login   <asvine_p@epitech.net>
// 
// Started on  Fri Jul 12 13:02:36 2013 pritesh asvinetsakou
// Last update Sun Jul 14 18:47:18 2013 pritesh asvinetsakou
//

#include "Game.hh"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Game::Game(): my_window(sf::VideoMode(1920, 1080), "Zappy Bibicy")
{
  this->sizex = 0;
  this->sizey = 0;
  map_view.setViewport(sf::FloatRect(0.25f, 0.f, 0.5f, 0.75));
  my_window.setView(map_view);

  if (!texture.loadFromFile("./Image/Case.png")) // Si le chargement a échoué                       
    {
      std::cout << "Erreur durant le chargement de l'image" << std::endl;
      return; // On ferme le programme                                                                
    }
  else // Si le chargement de l'image a réussi                                                        
    {
      texture.setSmooth(true);
      texture.setRepeated(true);
    }
}

Game::~Game()
{

}

void			Game::initialize()
{
 
}

void                    Game::update()
{
  std::cout << "update" << std::endl;
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
          if (this->clavier.key.code == sf::Keyboard::I)
            {
              map_view.zoom(0.5f);
              this->my_window.setView(this->map_view);
            }
	  if (this->clavier.key.code == sf::Keyboard::K)
            {
              map_view.zoom(1.5f);
              this->my_window.setView(this->map_view);
	    }
        }
    }
}

std::string		Game::m_getline(int &i)
{
  std::string		str = "";

  while (this->cmp[i] != '\n' && i < 4096 && cmp[i] != '\0')
    {
      str += cmp[i];
      i++;
    }
  i++;
  return (str);
}

void			Game::pars()
{
  int                   i;
  int			j;
  int                   ok;
  std::string		str;

 i = 0;
 while (i < 4096 && cmp[i] != '\0')
   {
     ok = 0;
     str = m_getline(i);
     j = 0;
      while (j < 24 && ok == 0)
	{
	  if (str.substr(0, 4) == cmd_c[j].action)
	    ok = 1;
	  else
	    j++;
	}
      if (ok == 1)
	{
	  cmd_c[j].fct(str.c_str(), *this);
	}
   }

}

void			Game::init_map()
{
  int	j;
  int	i;

  _map.resize(sizey);
  for(j = 0; j < this->sizey; j++)
    {
      for (i = 0; i < this->sizex; i++)
	this->_map[j].push_back(Case(i, j, &texture));
    } 
}

void			Game::draw()
{
  int		i;
  int		j;

  std::cout << "draw" << std::endl;
  for (j = 0; j < this->sizey; j++)
    {
      for (i = 0; i < this->sizex; i++)
	{
	  this->_map[j][i].draw_map(this->my_window);
	  this->_map[j][i].draw_res(this->my_window);
	}
    }
}

void		Game::set_case(int _x, int _y, int *res)
{
  this->_map[_y][_x].set_nourriture(res[0]);
  this->_map[_y][_x].set_linemate(res[1]);
  this->_map[_y][_x].set_sibur(res[2]);
  this->_map[_y][_x].set_deraumere(res[3]);
  this->_map[_y][_x].set_mendiane(res[4]);
  this->_map[_y][_x].set_phiras(res[5]);
  this->_map[_y][_x].set_thystame(res[6]);
}

void		Game::set_sizex(int _sizex)
{
  this->sizex = _sizex;
}

void		Game::set_sizey(int _sizey)
{
  this->sizey = _sizey;
}

void		Game::set_time(float _time)
{
  this->time = _time;
}

void		Game::set_finish(bool _finish)
{
  this->finish = _finish;
}

void		Game::set_pause(bool _pause)
{
  this->pause = _pause;
}

void		Game::set_teamName(std::string _name)
{
  this->team_name.push_back(_name);
}

void		Game::add_perso(Perso perso)
{
  this->_perso.push_back(perso);
}

/*Perso			&Game::getPlayerByNum()
{

}*/

sf::RenderWindow        &Game::getMywindow()
{
  return(this->my_window);
}

int			&Game::get_sizex()
{
  return(this->sizex);
}

int			&Game::get_sizey()
{
  return(this->sizey);
}

char			*Game::get_cmp()
{
  return(this->cmp);
}

bool			&Game::get_pause()
{
  return(this->pause);
}

float			&Game::get_time()
{
  return(this->time);
}

bool			&Game::get_finish()
{
  return(this->finish);
}

void			Game::set_cmp(char *_cmp)
{
  this->cmp = _cmp;
}
