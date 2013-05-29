#ifndef __BOMBE__HH__
#define __BOMBE__HH__

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "IObject.hh"

class Bombe : public IObject {

private:

  int	range;
  int	bombe;
  int	push;
  int	speed;
  int	life;

public:

  Bombe();
  ~Bombe();

  int getBombe() const;
  type getType() const;
  void setBombe(int);
};

#endif /* __BOMBE__HH__ */
