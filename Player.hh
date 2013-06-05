//
// Player.hh for Player in /home/strohe_d/Svn/kaboom
// 
// Made by Dorian Stroher
// Login   <strohe_d@epitech.net>
// 
// Started on  Fri May 31 14:46:53 2013 Dorian Stroher
// Last update Wed Jun  5 16:03:03 2013 Dorian Stroher
//
#ifndef __PLAYER_HH__
#define __PLAYER_HH__

#include "IObject.hh"
#include "Scene.hh"
#include "Map.hh"
#include "libgdl_gl-2012.4/include/Game.hpp"
#include "AObject.hh"

class Player:public IObject
{
public:
  Player(newin::SceneMgr *bbman, int col, int row, Map *map);
  bool getObj(IObject *);
  virtual ~Player() {}
  bool moveRight();
  void move(gdl::Input &i);
  bool moveLeft();
  bool moveUp();
  bool moveDown();
  virtual void moddifPos();
private:
  int _life;
  std::pair<int, int> _pos;
  std::map<std::pair<int, int>, IObject *>  *_map;
  AObject *_obj;
};

#endif
