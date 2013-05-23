//
// Wall.cpp for Wall in /home/strohe_d/Svn/kaboom/Valentin
// 
// Made by Dorian Stroher
// Login   <strohe_d@epitech.net>
// 
// Started on  Wed May 22 15:51:26 2013 Dorian Stroher
// Last update Wed May 22 15:52:20 2013 Dorian Stroher
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

int Wall::getRange()
{
  return (range);
}

int Wall::getBombe()
{
  return (bombe);
}

int Wall::getPush()
{
  return (push);
}

int Wall::getSpeed()
{
  return (speed);
}

int Wall::getLife()
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
