//
// Wall.hpp for Wall in /home/strohe_d/Svn/kaboom/Valentin
// 
// Made by Dorian Stroher
// Login   <strohe_d@epitech.net>
// 
// Started on  Wed May 22 15:52:54 2013 Dorian Stroher
// Last update Fri May 31 13:16:44 2013 Dorian Stroher
//

#ifndef __WALL__HH__
#define __WALL__HH__

#include "IBonus.hh"
#include "Scene.hh"

class Wall : public IBonus
{
public:
  virtual int getType() const{return (0);}
  Wall(newin::SceneMgr *bbman, int col, int row);
  virtual ~Wall();
};

#endif /* __HEART__HH__ */
