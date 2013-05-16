#include "Bombe.hpp"

Bombe::Bombe()
{
  range = 0;
  bombe = 1;
  push = 0;
  speed = 0;
  life = 0;
}


Bombe::~Bombe()
{
}

int Bombe::getRange()
{
  return (range);
}

int Bombe::getBombe()
{
  return (bombe);
}

int Bombe::getPush()
{
  return (push);
}

int Bombe::getSpeed()
{
  return (speed);
}

int Bombe::getLife()
{
  return (life);
}

void Bombe::setRange(int i)
{
  range = i;
}

void Bombe::setBombe(int i)
{
  bombe = i;
}

void Bombe::setPush(int i)
{
  push = i;
}

void	Bombe::setSpeed(int i)
{
  speed = i;
}

void	Bombe::setLife(int i)
{
  life = i;
}
