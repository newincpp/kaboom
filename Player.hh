//
// Player.hh for Player in /home/strohe_d/Svn/kaboom
// 
// Made by Dorian Stroher
// Login   <strohe_d@epitech.net>
// 
// Started on  Fri May 31 14:46:53 2013 Dorian Stroher
// Last update Thu Jun  6 15:43:09 2013 Dorian Stroher
//
#ifndef __PLAYER_HH__
#define __PLAYER_HH__

#include "IObject.hh"
#include "Scene.hh"
#include "Camera.hh"
#include "Map.hh"
#include "libgdl_gl-2012.4/include/Game.hpp"
#include "AObject.hh"

class Player:public IObject
{
public:
  Player(newin::SceneMgr *bbman, int col, int row, Map *map);
  virtual ObjectType getType() {return type__Player;}
  bool getObj(IObject *);
  virtual ~Player() {}
  bool checkMove(IObject *toto);
  void move(gdl::Input &i);
  virtual void moddifPos();
private:
  newin::Camera* _cam;
  int _life;
  std::pair<int, int> _pos;
  std::map<std::pair<int, int>, IObject *>  *_map;
  AObject *_obj;
  AObject *_objARM;
};

#endif
