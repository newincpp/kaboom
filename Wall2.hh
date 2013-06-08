//
// Wall2.hpp for Wall2 in /home/strohe_d/Svn/kaboom/Valentin
// 
// Made by Dorian Stroher
// Login   <strohe_d@epitech.net>
// 
// Started on  Wed May 22 15:52:54 2013 Dorian Stroher
// Last update Sat Jun  8 03:36:35 2013 Dorian Stroher
//

#ifndef __WALL2__HH__
#define __WALL2__HH__

#include "IObject.hh"
#include "Scene.hh"

class Wall2 : public IObject
{
public:
  virtual void moddifPos();
  Wall2(newin::SceneMgr *bbman, int col, int row);
  virtual ObjectType getType() {return type__Wall2;}
  virtual ~Wall2();
private:
  AObject *_obj;
  AObject *_objARM;
};

#endif /* __HEART__HH__ */
