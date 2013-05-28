#ifndef __HEART__HH__
#define __HEART__HH__

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "IObject.hh"

class Heart : public IObject {

private:

  int	range;
  int	bombe;
  int	push;
  int	speed;
  int	life;

public:

  Heart();
  virtual ~Heart();
  int getLife() const;
  void setLife(int);
  type getType() const;
};

#endif /* __HEART__HH__ */
