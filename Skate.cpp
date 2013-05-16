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

int Skate::getRange()
{
  return (range);
}

int Skate::getBombe()
{
  return (bombe);
}

int Skate::getPush()
{
  return (push);
}

int Skate::getSpeed()
{
  return (speed);
}

int Skate::getLife()
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
