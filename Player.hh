//
// Player.hh for Player in /home/strohe_d/Svn/kaboom
// 
// Made by Dorian Stroher
// Login   <strohe_d@epitech.net>
// 
// Started on  Fri May 31 14:46:53 2013 Dorian Stroher
// Last update Sun Jun  9 02:36:19 2013 Dorian Stroher
//
#ifndef __PLAYER_HH__
#define __PLAYER_HH__

#include "Bomb.hh"
#include "IObject.hh"
#include "Scene.hh"
#include "Camera.hh"
#include "Map.hh"
#include "libgdl_gl-2012.4/include/Game.hpp"
#include "AObject.hh"

class Player:public IObject
{
public:
  Player(newin::SceneMgr *bbman, int col, int row, Map *map, bool versus);
  virtual ObjectType getType() {return type__Player;}
  bool getObj(IObject *);
  virtual ~Player()
  {
    _obj->toogleRendering();
    (*_map)[_pos] = NULL;
    _obj->unsetPlayer();
  }
  bool checkMove(IObject *toto);
  virtual void deleteOBJ();
  void move(gdl::Input &i, gdl::GameClock const &c);
  virtual void moddifPos();
private:
  gdl::Clock _Clock;
  std::vector<Bomb *> _listBomb;
  bool _versus;
  newin::SceneMgr *_bbman;
  newin::Camera* _cam;
  newin::Light* _light;
  int _life;
  int _nbBomb;
  bool kaboom;
  std::pair<int, int> _pos;
  std::map<std::pair<int, int>, IObject *>  *_map;
  AObject *_obj;
  AObject *_objARM;
};

#endif
