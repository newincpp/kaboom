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

void Fire::setRange(int i)
{
  range = i;
}
