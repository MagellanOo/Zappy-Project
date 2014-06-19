//
// Perso.hh for perso in /home/asvine_p//Projets/Tek2/Zappy/sfml
// 
// Made by pritesh asvinetsakou
// Login   <asvine_p@epitech.net>
// 
// Started on  Tue Jul  2 16:28:16 2013 pritesh asvinetsakou
// Last update Sun Jul 14 20:51:56 2013 pritesh asvinetsakou
//

#ifndef         __PERSO_HH__
#define         __PERSO_HH__

#include "Object.hh"

#define X 75
#define Y 30

class Perso
{
public:
  Perso(int, int, int, int, int);
  ~Perso();
  void			initialize();
  void                  update(int, int, int);
  void                  draw(sf::RenderWindow &);
  void                  setMysprite(sf::Sprite);
  void			update(int x, int y);
  void			haut();
  void			bas();
  void			gauche();
  void			droite();
  void			setx(int);
  void			sety(int);
  void			setDirection(int);
  void			setNumteam(int);
  void			setLevel(int);
  void                  setNum(int);
  int                   &getNum();
  void			setBroadcast(bool);
  void                  setIncentation(bool);
  int			&getx();
  int			&gety();
  int			&getDirection();
  void			add_inventaire(int *);
			
private:
  sf::Sprite            &getMysprite();
  sf::Texture		perso;
  sf::Sprite            nv1;
  int			num;
  int			x;
  int			y;
  int			direction;
  int			level;
  int			bag[7];
  int			team;
  bool			broadcast;
  bool			incentation;
};

#endif
