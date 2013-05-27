#include "BFactory.hpp"
#include "IObject.hh"

BFactory::BFactory()
{
}

BFactory::~BFactory()
{
}

void	BFactory::createMap()
{
  this->extra["fire"] = &BFactory::burn;
  this->extra["bombe"] = &BFactory::explode;
  this->extra["roller"] = &BFactory::rolling;
  this->extra["skate"] = &BFactory::backflip;
  this->extra["heart"] = &BFactory::life;
  this->extra["Wall"] = &BFactory::wall;
}

IObject *BFactory::burn()
{
  return (new Fire);
}

IObject *BFactory::explode()
{
  return (new Bombe);
}

IObject *BFactory::rolling()
{
  return (new Roller);
}

IObject *BFactory::backflip()
{
  return (new Skate);
}

IObject *BFactory::life()
{
  return (new Heart);
}

IObject *BFactory::wall()
{
  return (new Wall);
}

IObject	*BFactory::whichOne(std::string bonus)
{
  //  IObject	*(*func)(); Ne sert pas normalement

  return ((this->*extra[bonus]) ());
}
