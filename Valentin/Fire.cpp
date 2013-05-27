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

type Fire::getType() const
{
  type tmp;

  tmp = fire;
  return (tmp);
}

int Fire::getRange() const
{
  return (range);
}

int Fire::getBombe() const
{
  return (bombe);
}

int Fire::getPush() const
{
  return (push);
}

int Fire::getSpeed() const
{
  return (speed);
}

int Fire::getLife() const
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
