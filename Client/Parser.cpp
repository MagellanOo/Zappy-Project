//
// parser.cpp for parser in /home/asvine_p//Projets/Tek2/Zappy/sfml
// 
// Made by pritesh asvinetsakou
// Login   <asvine_p@epitech.net>
// 
// Started on  Fri Jul 12 14:37:55 2013 pritesh asvinetsakou
// Last update Sun Jul 14 17:51:32 2013 pritesh asvinetsakou
//

#include "Parser.hh"
#include "Game.hh"

void		parser::bct(const char *args, Game &game)
{
  int		x;
  int		y;
  int		ress[7];
  int		pos;
  int		i = 0;
  std::string	tmp;
  
  args += 4;
  std::cout << "bct" << std::endl;
  while (args[i] != ' ')
    {
      tmp += args[i];
      i++; 
    }
  std::stringstream	stream(tmp);

  stream >> x;
  i = i + 1;
  tmp = "";
  while (args[i] != ' ')
    {
      tmp += args[i];
      i++; 
    }
  std::stringstream	stream2(tmp);
  stream2 >> y;

  
  if (x <= 0 || y <= 0)
    return;

  for (pos = 0; pos < 7; pos++)
    {
      i = i + 1;
      tmp = "";
      while (args[i] != ' ' && args[i] != '\n')
	{
	  tmp += args[i];
	  i++; 
	}
      std::stringstream	stream3(tmp);
      if (!stream3)
	break;
      stream3 >> ress[pos];
    }
  /* if (pos < 7)
     ERROR;*/
  game.set_case(x, y, ress);
}

void	       parser::msz(const char *args, Game &game)
{
  int		x;
  int		y;
  int           i = 0;
  std::string   tmp;

  std::cout << "msz" << std::endl;
  args += 4;
  while (args[i] != ' ')
    {
      tmp += args[i];
      i++;
    }
  std::stringstream     stream(tmp);

  stream >> x;
  i = i + 1;
  tmp = "";
  while (args[i] != ' ')
    {
      tmp += args[i];
      i++;
    }
  std::stringstream     stream2(tmp);
  stream2 >> y;

 
  //  if (x <= 0 || y <= 0)
  // ERROR;

  game.set_sizex(x);
  game.set_sizey(y);
  game.init_map();
}

void		  parser::sgt(const char *args, Game &game)
{
  /*  float		t;

      args += 4;
      std::stringstream	stream(args);
      stream >> t;
  
      if (t <= 0)
      ERROR;
      game.set_time(t);*/
}

void		  parser::tna(const char *args, Game &game)
{
  /*    string		team;

	args += 4;
	std::stringstream     stream(args);
	stream >> team;
	game.set_teamName(team);
  */
}

void		  parser::pnw(const char *args, Game &game)
{
  /* int           x;
     int           y;
     int           dir;
     int		level;
     int		num_team;

     args += 4;
     std::stringstream     stream(args);
     stream >> x;
     stream >> y;
     stream >> dir;
     stream >> team;
     //ajouter Peso dans le vector
     Perso->setx(x);
     Perso->sety(y);
     Perso->setDirection(dir);
     Perso->setLevel(level);
     Perso->setNumteam(num_team);*/
}

void		parser::ppo(const char *args, Game &game)
{
  /*    int		x;
	int		y;
	int		dir;

	args += 4;
	std::stringstream	stream(args);
	stream >> x;
	stream >> y;
	stream >> dir;
	Perso->setx(x);
	Perso->sety(y);
	Perso->setDirection(dir);*/
}

void		  parser::plv(const char *args, Game &game)
{
  /*    int		level;

	args += 4;
	std::stringstream	stream(args);
	stream >> level;
	Perso->setLevel(level);*/
}

void		 parser::pin(const char *args, Game &game)
{
  /* int	        bag[7];
     int		num;
     int		x;
     int		y;
     int		pos = 0;
     args += 4;
     std::stringstream     stream(args);
     stream >> num;
     stream >> x;
     stream >> y;
     for (pos = 0, pos < 7 pos++)
     stream >> bag[pos];*/
  
}

void		 parser::pex(const char *args, Game &game)
{

  //  perso.setBroadcast(true);  
}

void		  parser::pbc(const char *args, Game &game)
{
  /* Perso		Perso;

     perso.setIncentation(true);*/
}

void		  parser::pic(const char *args, Game &game)
{
  /*  Perso		Perso;

      perso.setIncentation(false);*/
}

void		  parser::pie(const char *args, Game &game)
{
  
}

void		  parser::pfk(const char *args, Game &game)
{
  
}

void		  parser::pdr(const char *args, Game &game)
{
  
}

void		  parser::pgt(const char *args, Game &game)
{

}

void		  parser::pdi(const char *args, Game &game)
{

}

void		  parser::enw(const char *args, Game &game)
{

}

void		  parser::eht(const char *args, Game &game)
{

}

void		  parser::ebo(const char *args, Game &game)
{

}

void		  parser::edi(const char *args, Game &game)
{

}

void		  parser::seg(const char *args, Game &game)
{

}

void		  parser::smg(const char *args, Game &game)
{

}

void		  parser::suc(const char *args, Game &game)
{
  std::cout << "suc" << std::endl;
}

void		  parser::sbp(const char *args, Game &game)
{

}
