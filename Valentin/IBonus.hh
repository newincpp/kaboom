#ifndef __IOBJECT__HH__
#define __IOBJECT__HH__

#include <iostream>
#include <vector>
#include <string>
#include <list>

enum type { fire,
	    bomb,
	    heart,
	    skate,
	    roller,
	    wall };


class IObject {

private:

public:

  virtual ~IObject();

  // virtual int getRange() const = 0;
  // virtual int getBombe() const = 0;
  // virtual int getPush() const = 0;
  // virtual int getSpeed() const = 0;
  // virtual int getLife() const = 0;
  // virtual void setRange(int) = 0;
  // virtual void setBombe(int) = 0;
  // virtual void setPush(int) = 0;
  // virtual void setSpeed(int) = 0;
  // virtual void setLife(int) = 0;
  virtual type getType() const = 0;
};

#endif /* __IObject__HH__ */
