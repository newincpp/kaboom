#ifndef __ROLLER__HH__
#define __ROLLER__HH__

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "IObject.hh"

class Roller : public IObject {

private:

  int	range;
  int	bombe;
  int	push;
  int	speed;
  int	life;

public:

  Roller();
  ~Roller();

  int getPush() const;
  void setPush(int);
  type getType() const;
};

#endif /* __ROLLER__HH__ */
