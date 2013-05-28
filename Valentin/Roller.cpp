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

int Roller::getPush() const
{
  return (push);
}

void Roller::setPush(int i)
{
  push = i;
}
