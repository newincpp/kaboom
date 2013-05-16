#include "Heart.hpp"

Heart::Heart()
{
  range = 0;
  bombe = 0;
  push = 0;
  speed = 0;
  life = 1;
}


Heart::~Heart()
{
}

int Heart::getRange()
{
  return (range);
}

int Heart::getBombe()
{
  return (bombe);
}

int Heart::getPush()
{
  return (push);
}

int Heart::getSpeed()
{
  return (speed);
}

int Heart::getLife()
{
  return (life);
}

void Heart::setRange(int i)
{
  range = i;
}

void Heart::setBombe(int i)
{
  bombe = i;
}

void Heart::setPush(int i)
{
  push = i;
}

void	Heart::setSpeed(int i)
{
  speed = i;
}

void	Heart::setLife(int i)
{
  life = i;
}
