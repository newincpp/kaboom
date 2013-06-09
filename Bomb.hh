//
// Bomb.hpp for Bomb in /home/strohe_d/Svn/kaboom/Valentin
// 
// Made by Dorian Stroher
// Login   <strohe_d@epitech.net>
// 
// Started on  Wed May 22 15:52:54 2013 Dorian Stroher
// Last update Sat Jun  8 22:05:34 2013 Dorian Stroher
//

#ifndef __Bpmb__HH__
#define __Bomb__HH__

#include "IObject.hh"
#include "Scene.hh"

class Bomb : public IObject
{
public:
  virtual void moddifPos();
  Bomb(newin::SceneMgr *bbman, int col, int row, int power);
  bool    explode(std::map<std::pair<int, int>, IObject *>  *_map);
  virtual ObjectType getType() {return type__Bomb;}
  virtual ~Bomb();
private:
  AObject *_obj;
  AObject *_objARM;
  gdl::Clock _myClock;
  int _power;
  int _col;
  int _row;
};

#endif /* __HEART__HH__ */
