#ifndef __BFACOTRY__HPP__
#define __BFACTORY__HPP__

#include <map>
#include "IObject.hh"
#include "Fire.hpp"
#include "Bombe.hpp"
#include "Heart.hpp"
#include "Wall.hpp"
#include "Roller.hpp"
#include "Skate.hpp"

class BFactory {

private:

  typedef IObject *(BFactory::*ptr)();
  std::map<std::string, ptr> extra;

public:

  BFactory();
  ~BFactory();

  IObject	*burn();
  IObject	*explode();
  IObject	*rolling();
  IObject	*backflip();
  IObject	*life();
  IObject	*wall();
  void	createMap();
  IObject	*whichOne(std::string);
};

#endif /* __BFACTORY__HPP__ */
