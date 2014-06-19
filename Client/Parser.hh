//
// Parser.hh for Parser in /home/asvine_p//Projets/Tek2/Zappy/sfml
// 
// Made by pritesh asvinetsakou
// Login   <asvine_p@epitech.net>
// 
// Started on  Sat Jul 13 17:02:20 2013 pritesh asvinetsakou
// Last update Sun Jul 14 17:37:54 2013 pritesh asvinetsakou
//

#ifndef			__PARSER_HH__
#define			__PARSER_HH__

#include <iostream>
#include <sstream>
//#include "Game.hh"
//#include "Case.hh"
//#include "Perso.hh"

class Game;

namespace parser
{
    void	bct(const char *args, Game &game);
    void	msz(const char *args, Game &game);  
    void	sgt(const char *args, Game &game);
    void	tna(const char *args, Game &game);
    void	pnw(const char *args, Game &game);
    void	ppo(const char *args, Game &game);
    void	plv(const char *args, Game &game);
    void	pin(const char *args, Game &game);
    void	pex(const char *args, Game &game);
    void	pbc(const char *args, Game &game);
    void        pic(const char *args, Game &game);
    void        pie(const char *args, Game &game);
    void        pfk(const char *args, Game &game);
    void        pdr(const char *args, Game &game);
    void        pgt(const char *args, Game &game);
    void	pdi(const char *args, Game &game);
    void	enw(const char *args, Game &game);
    void	eht(const char *args, Game &game);
    void        ebo(const char *args, Game &game);
    void	edi(const char *args, Game &game);
    void	seg(const char *args, Game &game);
    void	smg(const char *args, Game &game);
    void	suc(const char *args, Game &game);
    void	sbp(const char *args, Game &game); 
}

typedef struct          s_cmd_c
{
  char                  action[24];
  void                  (*fct)(const char *str, Game &game);
}                       t_cmd_c;

static t_cmd_c          cmd_c[] =
  {
    {"msz ", parser::msz},
    {"bct ", parser::bct},
    {"tna ", parser::tna},
    {"pnw ", parser::pnw},
    {"ppo ", parser::ppo},
    {"plv ", parser::plv},
    {"pin ", parser::pin},
    {"pex ", parser::pex},
    {"pbc ", parser::pbc},
    {"pic ", parser::pic},
    {"pie ", parser::pie},
    {"pfk ", parser::pfk},
    {"pdr ", parser::pdr},
    {"pgt ", parser::pgt},
    {"pdi ", parser::pdi},
    {"enw ", parser::enw},
    {"eht ", parser::eht},
    {"ebo ", parser::ebo},
    {"edi ", parser::edi},
    {"sgt ", parser::sgt},
    {"seg ", parser::seg},
    {"smg ", parser::smg},
    {"suc\n", parser::suc},
    {"sbp\n", parser::sbp}
  };



#endif
