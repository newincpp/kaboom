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

int Heart::getLife() const
{
  return (life);
}

void	Heart::setLife(int i)
{
  life = i;
}
