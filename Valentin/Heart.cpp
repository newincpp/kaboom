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

type Heart::getType() const
{
  type	tmp;

  tmp = heart;
  return (tmp);
}

int Heart::getRange() const
{
  return (range);
}

int Heart::getBombe() const
{
  return (bombe);
}

int Heart::getPush() const
{
  return (push);
}

int Heart::getSpeed() const
{
  return (speed);
}

int Heart::getLife() const
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
