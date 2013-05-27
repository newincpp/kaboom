#ifndef __BFACOTRY__HPP__
#define __BFACTORY__HPP__

#include <map>
#include "IBonus.hh"
#include "Fire.hpp"
#include "Bombe.hpp"
#include "Heart.hpp"
#include "Wall.hpp"
#include "Roller.hpp"
#include "Skate.hpp"

class BFactory {

private:

  typedef IBonus *(BFactory::*ptr)();
  std::map<std::string, ptr> extra;

public:

  BFactory();
  ~BFactory();

  IBonus	*burn();
  IBonus	*explode();
  IBonus	*rolling();
  IBonus	*backflip();
  IBonus	*life();
  IBonus	*wall();
  void	createMap();
  IBonus	*whichOne(std::string);
};

#endif /* __BFACTORY__HPP__ */
