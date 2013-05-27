//
// Wall.cpp for Wall in /home/strohe_d/Svn/kaboom/Valentin
// 
// Made by Dorian Stroher
// Login   <strohe_d@epitech.net>
// 
// Started on  Wed May 22 15:51:26 2013 Dorian Stroher
// Last update Wed May 22 17:56:01 2013 Valentin Laurent
//

#include "Wall.hpp"

Wall::Wall()
{
  range = 0;
  bombe = 0;
  push = 0;
  speed = 0;
  life = 1;
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

int Wall::getRange() const
{
  return (range);
}

int Wall::getBombe() const
{
  return (bombe);
}

int Wall::getPush() const
{
  return (push);
}

int Wall::getSpeed() const
{
  return (speed);
}

int Wall::getLife() const
{
  return (life);
}

void Wall::setRange(int i)
{
  range = i;
}

void Wall::setBombe(int i)
{
  bombe = i;
}

void Wall::setPush(int i)
{
  push = i;
}

void	Wall::setSpeed(int i)
{
  speed = i;
}

void	Wall::setLife(int i)
{
  life = i;
}
