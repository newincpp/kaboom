//
// Bomb.hpp for Bomb in /home/strohe_d/Svn/kaboom/Valentin
// 
// Made by Dorian Stroher
// Login   <strohe_d@epitech.net>
// 
// Started on  Wed May 22 15:52:54 2013 Dorian Stroher
// Last update Sun Jun  9 06:40:20 2013 Dorian Stroher
//

#ifndef __BonusLife__HH__
#define __BonusLife__HH__

#include "IObject.hh"
#include "Scene.hh"

class BonusLife : public IObject
{
public:
  virtual void moddifPos();
  BonusLife(newin::SceneMgr *bbman, int col, int row);
  virtual ObjectType getType() {return type__BonusLife;}
  virtual void deleteOBJ();
  virtual ~BonusLife();
private:
  AObject *_obj;
  AObject *_objARM;
};

#endif /* __HEART__HH__ */
