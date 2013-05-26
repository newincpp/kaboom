//
// Wall.hpp for Wall in /home/strohe_d/Svn/kaboom/Valentin
// 
// Made by Dorian Stroher
// Login   <strohe_d@epitech.net>
// 
// Started on  Wed May 22 15:52:54 2013 Dorian Stroher
// Last update Wed May 22 15:52:54 2013 Dorian Stroher
//

#ifndef __WALL__HH__
#define __WALL__HH__

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "IBonus.hh"

class Wall : public IBonus {

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
  void setRange();
  void setBombe();
  void setPush();
  void setSpeed();
  void setLife();
};

#endif /* __HEART__HH__ */