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

int Skate::getSpeed() const
{
  return (speed);
}

void	Skate::setSpeed(int i)
{
  speed = i;
}
