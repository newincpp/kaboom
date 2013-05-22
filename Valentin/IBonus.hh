#ifndef __IBONUS__HH__
#define __IBONUS__HH__

#include <iostream>
#include <vector>
#include <string>
#include <list>

class IBonus {

private:

public:

  virtual ~IBonus();

  virtual int getRange() const = 0;
  virtual int getBombe() const = 0;
  virtual int getPush() const = 0;
  virtual int getSpeed() const = 0;
  virtual int getLife() const = 0;
  virtual void setRange() = 0;
  virtual void setBombe() = 0;
  virtual void setPush() = 0;
  virtual void setSpeed() = 0;
  virtual void setLife() = 0;
};

#endif /* __IBONUS__HH__ */
