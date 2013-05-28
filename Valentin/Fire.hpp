#ifndef __FIRE__HH__
#define __FIRE__HH__

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "IObject.hh"

class Fire : public IObject {

private:

  int	range;
  int	bombe;
  int	push;
  int	speed;
  int	life;

public:

  Fire();
  ~Fire();

  int getRange() const;
  type getType() const;
  void setRange(int);
};

#endif /* __ROLLER__HH__ */
