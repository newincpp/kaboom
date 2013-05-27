#include "Roller.hpp"

Roller::Roller()
{
  range = 0;
  bombe = 0;
  push = 1;
  speed = 0;
  life = 0;
}


Roller::~Roller()
{
}

type Roller::getType() const
{
  type	tmp;

  tmp = roller;
  return (tmp);
}

int Roller::getRange() const
{
  return (range);
}

int Roller::getBombe() const
{
  return (bombe);
}

int Roller::getPush() const
{
  return (push);
}

int Roller::getSpeed() const
{
  return (speed);
}

int Roller::getLife() const
{
  return (life);
}

void Roller::setRange(int i)
{
  range = i;
}

void Roller::setBombe(int i)
{
  bombe = i;
}

void Roller::setPush(int i)
{
  push = i;
}

void	Roller::setSpeed(int i)
{
  speed = i;
}

void	Roller::setLife(int i)
{
  life = i;
}
