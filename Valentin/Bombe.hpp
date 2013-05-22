#ifndef __BOMBE__HH__
#define __BOMBE__HH__

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "IBonus.hh"

class Bombe : public IBonus {

private:

  int	range;
  int	bombe;
  int	push;
  int	speed;
  int	life;

public:

  Bombe();
  ~Bombe();

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

#endif /* __BOMBE__HH__ */
