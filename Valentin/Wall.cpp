//
// Wall.cpp for Wall in /home/strohe_d/Svn/kaboom/Valentin
// 
// Made by Dorian Stroher
// Login   <strohe_d@epitech.net>
// 
// Started on  Wed May 22 15:51:26 2013 Dorian Stroher
// Last update Tue May 28 14:40:52 2013 Valentin Laurent
//

#include "Wall.hpp"

Wall::Wall()
{
  range = 0;
  bombe = 0;
  push = 0;
  speed = 0;
  life = 0;
  brick = 1;
}

Wall::~Wall()
{
}

type Wall::getType() const
{
  type tmp;

  tmp = wall;
  return (tmp);
}

int Wall::getBrick() const
{
  return (brick);
}

void Wall::setBrick(int i)
{
  brick = i;
}
