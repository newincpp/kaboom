#include "Fire.hpp"

Fire::Fire()
{
  range = 1;
  bombe = 0;
  push = 0;
  speed = 0;
  life = 0;
}


Fire::~Fire()
{
}

int Fire::getRange()
{
  return (range);
}

int Fire::getBombe()
{
  return (bombe);
}

int Fire::getPush()
{
  return (push);
}

int Fire::getSpeed()
{
  return (speed);
}

int Fire::getLife()
{
  return (life);
}

void Fire::setRange(int i)
{
  range = i;
}

void Fire::setBombe(int i)
{
  bombe = i;
}

void Fire::setPush(int i)
{
  push = i;
}

void	Fire::setSpeed(int i)
{
  speed = i;
}

void	Fire::setLife(int i)
{
  life = i;
}
