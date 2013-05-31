//
// Player.hh for Player in /home/strohe_d/Svn/kaboom
// 
// Made by Dorian Stroher
// Login   <strohe_d@epitech.net>
// 
// Started on  Fri May 31 14:46:53 2013 Dorian Stroher
// Last update Fri May 31 16:49:51 2013 Dorian Stroher
//
#ifndef __PLAYER_HH__
#define __PLAYER_HH__

#include "Map.hh"

class Player:public IObject
{
public:
  Player(newin::SceneMgr *bbman, std::pair<int, int> pos, Map *map);
  bool getObj(IObject *);
  virtual ~Player() {}
  bool moveRight();
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
