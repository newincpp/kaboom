#include "Skate.hpp"

Skate::Skate()
{
  range = 0;
  bombe = 0;
  push = 0;
  speed = 1;
  life = 0;
}


Skate::~Skate()
{
}

type Skate::getType() const
{
  type tmp;

  tmp = skate;
  return (tmp);
}

int Skate::getRange() const
{
  return (range);
}

int Skate::getBombe() const
{
  return (bombe);
}

int Skate::getPush() const
{
  return (push);
}

int Skate::getSpeed() const
{
  return (speed);
}

int Skate::getLife() const
{
  return (life);
}

void Skate::setRange(int i)
{
  range = i;
}

void Skate::setBombe(int i)
{
  bombe = i;
}

void Skate::setPush(int i)
{
  push = i;
}

void	Skate::setSpeed(int i)
{
  speed = i;
}

void	Skate::setLife(int i)
{
  life = i;
}
