//
// IBonus.hh for IBonus in /home/strohe_d/Svn/kaboom
// 
// Made by Dorian Stroher
// Login   <strohe_d@epitech.net>
// 
// Started on  Mon May 27 17:26:10 2013 Dorian Stroher
// Last update Sat Jun  8 19:23:50 2013 Dorian Stroher
//

#ifndef __IObject__HH__
#define __IObject__HH__

#include <iostream>
#include <vector>
#include <string>
#include <list>
#define SIZECASE 1

enum ObjectType
  {
    type__Wall,
    type__Wall2,
    type__Bomb,
    type__Player
  };
class IObject
{
public:
  IObject() {}
  virtual void moddifPos() = 0;
  virtual ObjectType getType() = 0;
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
