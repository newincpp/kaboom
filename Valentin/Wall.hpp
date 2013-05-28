//
// Wall.hpp for Wall in /home/strohe_d/Svn/kaboom/Valentin
// 
// Made by Dorian Stroher
// Login   <strohe_d@epitech.net>
// 
// Started on  Wed May 22 15:52:54 2013 Dorian Stroher
// Last update Tue May 28 14:40:56 2013 Valentin Laurent
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
  int	brick;

public:

  Wall();
  virtual ~Wall();
  int getBrick() const;
  void setBrick(int);
  type getType() const;
};

#endif /* __HEART__HH__ */
