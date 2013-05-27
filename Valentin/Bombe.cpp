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

type	Bombe::getType() const
{
  type tmp;

  tmp = bomb;
  return (tmp);
}

int Bombe::getRange() const
{
  return (range);
}

int Bombe::getBombe() const
{
  return (bombe);
}

int Bombe::getPush() const
{
  return (push);
}

int Bombe::getSpeed() const
{
  return (speed);
}

int Bombe::getLife() const
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
