//
// Wall.hpp for Wall in /home/strohe_d/Svn/kaboom/Valentin
// 
// Made by Dorian Stroher
// Login   <strohe_d@epitech.net>
// 
// Started on  Wed May 22 15:52:54 2013 Dorian Stroher
// Last update Fri Jun  7 18:10:46 2013 Dorian Stroher
//

#ifndef __WALL__HH__
#define __WALL__HH__

#include "IObject.hh"
#include "Scene.hh"

class Wall : public IObject
{
public:
  virtual void moddifPos();
  Wall(newin::SceneMgr *bbman, int col, int row);
  virtual ObjectType getType() {return type__Wall;}
  virtual ~Wall();
private:
  AObject *_obj;
  AObject *_objARM;
};

#endif /* __HEART__HH__ */
