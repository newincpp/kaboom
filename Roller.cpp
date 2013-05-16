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

int Roller::getRange()
{
  return (range);
}

int Roller::getBombe()
{
  return (bombe);
}

int Roller::getPush()
{
  return (push);
}

int Roller::getSpeed()
{
  return (speed);
}

int Roller::getLife()
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
