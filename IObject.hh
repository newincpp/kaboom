//
// IBonus.hh for IBonus in /home/strohe_d/Svn/kaboom
// 
// Made by Dorian Stroher
// Login   <strohe_d@epitech.net>
// 
// Started on  Mon May 27 17:26:10 2013 Dorian Stroher
// Last update Fri May 31 14:26:11 2013 Dorian Stroher
//

#ifndef __IObject__HH__
#define __IObject__HH__

#include <iostream>
#include <vector>
#include <string>
#include <list>

class IObject
{
public:
  IObject() {}
  virtual int getType() const = 0;
  virtual ~IObject() {}
  /*virtual int getBombe() const = 0;
  virtual int getPush() const = 0;
  virtual int getSpeed() const = 0;
  virtual int getLife() const = 0;
  virtual void setRange() = 0;
  virtual void setBombe() = 0;
  virtual void setPush() = 0;
  virtual void setSpeed() = 0;
  virtual void setLife() = 0;*/
};

#endif /* __IBONUS__HH__ */
