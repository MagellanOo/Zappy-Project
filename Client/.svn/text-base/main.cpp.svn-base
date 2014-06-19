//
// main.cpp for main in /home/asvine_p//Projets/Tek2/Zappy/sfml
// 
// Made by pritesh asvinetsakou
// Login   <asvine_p@epitech.net>
// 
// Started on  Thu Jun 13 17:16:46 2013 pritesh asvinetsakou
// Last update Thu Jul 11 14:29:47 2013 pritesh asvinetsakou
//

#include <iostream>
#include "Object.hh"
#include "Map.hh"
#include "Perso.hh"
#include "Ressources.hh"

int	main()
{
  Map				other; 
  Perso				perso;
  Object			my_object;
  Ressources			ressources;
 
  other.initialize();
  perso.initialize();
  ressources.initialize();
    // Start game loop
  my_object.getMywindow().clear();
  while (my_object.getMywindow().isOpen())
      {
	my_object.update();
      	other.draw(my_object.getMywindow(), 10, 10);
	ressources.draw(my_object.getMywindow(), 0, 1, 2);
	ressources.draw(my_object.getMywindow(), 5, 1, 2);
	perso.draw(my_object.getMywindow(), 0, 0, 2);
	my_object.getMywindow().display();
	}
    return EXIT_SUCCESS;
}
