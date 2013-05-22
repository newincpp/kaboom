#ifndef __SKATE__HH__
#define __SKATE__HH__

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "IBonus.hh"

class Skate : public IBonus {

private:

  int	range;
  int	bombe;
  int	push;
  int	speed;
  int	life;

public:

  Skate();
  ~Skate();

  int getRange() const;
  int getBombe() const;
  int getPush() const;
  int getSpeed() const;
  int getLife() const;
  void setRange();
  void setBombe();
  void setPush();
  void setSpeed();
  void setLife();
};

#endif /* __SKATE__HH__ */
