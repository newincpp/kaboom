#ifndef AOBJECT_H_
# define AOBJECT_H_

#include "Vector3D.hh"
#include "libgdl_gl-2012.4/include/Game.hpp"
#include "libgdl_gl-2012.4/include/Clock.hpp"
#include <stdlib.h>
class Player;

class AObject
{
  public:
  AObject(const newin::Vector3D<GLfloat>& p = newin::Vector3D<GLfloat>(), const newin::Vector3D<GLfloat>& r = newin::Vector3D<GLfloat>(), const newin::Vector3D<GLfloat>& c = newin::Vector3D<GLfloat>(1,1,1)) : _pos(p), _rot(r), _col(c), _willRendered(true) { }
  virtual AObject& operator=(const AObject& o) { _pos = o._pos; _rot = o._rot; _col = o._col; _willRendered = o._willRendered; return *this; }
  virtual void initialize(void) = 0;
  virtual void update(gdl::GameClock const &, gdl::Input &) = 0;
  virtual void draw(void) = 0;
  virtual void setPos(const newin::Vector3D<GLfloat>& p) { _pos = p; }
  virtual void setRot(const newin::Vector3D<GLfloat>& r) { _rot = r; }
  void setPlayer(Player *play) {_play.push_back(play); }
  void unsetPlayer()
  {
   _play.pop_back();
  }
  virtual void setColor(const newin::Vector3D<GLfloat>& c) { _col = c; }
  virtual newin::Vector3D<GLfloat> getPos() const { return _pos; }
  virtual newin::Vector3D<GLfloat> getRot() const { return _rot; }
  virtual newin::Vector3D<GLfloat> getColor() const { return _col; }
  virtual std::string getIdentifier() const {
    return _identifier;
  }
  virtual void toogleRendering() { _willRendered = !_willRendered;}
  virtual bool renderStatus() { return _willRendered; }
  virtual void setIdentifier(const std::string& i) {
    _identifier = i;
  }
private:
  std::string _identifier;
protected:
  newin::Vector3D<GLfloat> _pos;
  newin::Vector3D<GLfloat> _rot;
  newin::Vector3D<GLfloat> _col;
  std::vector<Player *>_play;
  bool _willRendered;
};


#endif /* !AOBJECT_H_ */
