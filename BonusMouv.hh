//
// Bomb.hpp for Bomb in /home/strohe_d/Svn/kaboom/Valentin
// 
// Made by Dorian Stroher
// Login   <strohe_d@epitech.net>
// 
// Started on  Wed May 22 15:52:54 2013 Dorian Stroher
// Last update Sun Jun  9 06:14:51 2013 Dorian Stroher
//

#ifndef __BonusMouv__HH__
#define __BonusMouv__HH__

#include "IObject.hh"
#include "Scene.hh"

class BonusMouv : public IObject
{
public:
  virtual void moddifPos();
  BonusMouv(newin::SceneMgr *bbman, int col, int row);
  virtual ObjectType getType() {return type__BonusMouv;}
  virtual void deleteOBJ();
  virtual ~BonusMouv();
private:
  AObject *_obj;
  AObject *_objARM;
};

#endif /* __HEART__HH__ */
