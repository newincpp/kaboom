//
// Wall.hpp for Wall in /home/strohe_d/Svn/kaboom/Valentin
// 
// Made by Dorian Stroher
// Login   <strohe_d@epitech.net>
// 
// Started on  Wed May 22 15:52:54 2013 Dorian Stroher
// Last update Mon May 27 17:14:20 2013 Valentin Laurent
//

#ifndef __WALL__HH__
#define __WALL__HH__

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "IObject.hh"

class Wall : public IObject {

private:

  int	range;
  int	bombe;
  int	push;
  int	speed;
  int	life;

public:

  Wall();
  virtual ~Wall();
  int getRange() const;
  int getBombe() const;
  int getPush() const;
  int getSpeed() const;
  int getLife() const;
  void setRange(int);
  void setBombe(int);
  void setPush(int);
  void setSpeed(int);
  void setLife(int);
  type getType() const;
};

#endif /* __HEART__HH__ */
