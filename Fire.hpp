#ifndef __FIRE__HH__
#define __FIRE__HH__

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "IBonus.hh"

class Fire : public IBonus {

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
  int getBombe() const;
  int getPush() const;
  int getSpeed() const;
  int getLife() const;
  void setRange(int);
  void setBombe(int);
  void setPush(int);
  void setSpeed(int);
  void setLife(int);
};

#endif /* __FIRE__HH__ */
