#ifndef __ROLLER__HH__
#define __ROLLER__HH__

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "IBonus.hh"

class Roller : public IBonus {

private:

  int	range;
  int	bombe;
  int	push;
  int	speed;
  int	life;

public:

  Roller();
  ~Roller();

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
  type getType() const;
};

#endif /* __ROLLER__HH__ */
