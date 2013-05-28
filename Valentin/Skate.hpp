#ifndef __SKATE__HH__
#define __SKATE__HH__

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "IObject.hh"

class Skate : public IObject {

private:

  int	range;
  int	bombe;
  int	push;
  int	speed;
  int	life;

public:

  Skate();
  ~Skate();

  int getSpeed() const;
  void setSpeed(int);
   type getType() const;
};

#endif /* __SKATE__HH__ */
