#include "BFactory.hpp"
#include "IBonus.hh"

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
  this->extra["Wall"] = &BFactory::Wall;
}

IBonus *BFactory::burn()
{
  return (new Fire);
}

IBonus *BFactory::explode()
{
  return (new Bombe);
}

IBonus *BFactory::rolling()
{
  return (new Roller);
}

IBonus *BFactory::backflip()
{
  return (new Skate);
}

IBonus *BFactory::life()
{
  return (new Heart);
}

IBonus *BFactory::Wall()
{
  return (new Wall);
}

void	BFactory::whichOne(std::string bonus)
{
  IBonus	*(*func)();

  func = extra[bonus]();
  func();
}
