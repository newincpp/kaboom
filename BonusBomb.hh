//
// Bomb.hpp for Bomb in /home/strohe_d/Svn/kaboom/Valentin
// 
// Made by Dorian Stroher
// Login   <strohe_d@epitech.net>
// 
// Started on  Wed May 22 15:52:54 2013 Dorian Stroher
// Last update Sun Jun  9 02:48:13 2013 Dorian Stroher
//

#ifndef __BonusBomb__HH__
#define __BonusBomb__HH__

#include "IObject.hh"
#include "Scene.hh"

class BonusBomb : public IObject
{
public:
  virtual void moddifPos();
  BonusBomb(newin::SceneMgr *bbman, int col, int row);
  virtual ObjectType getType() {return type__BonusBomb;}
  virtual void deleteOBJ();
  virtual ~BonusBomb();
private:
  AObject *_obj;
  AObject *_objARM;
};

#endif /* __HEART__HH__ */
