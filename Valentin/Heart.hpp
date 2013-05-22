#ifndef __HEART__HH__
#define __HEART__HH__

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "IBonus.hh"

class HEART : public IBonus {

private:

  int	range;
  int	bombe;
  int	push;
  int	speed;
  int	life;

public:

  Heart();
  ~Heart();

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

#endif /* __HEART__HH__ */
