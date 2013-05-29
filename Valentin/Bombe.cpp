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

int Bombe::getBombe() const
{
  return (bombe);
}

void Bombe::setBombe(int i)
{
  bombe = i;
}
