#ifndef AOBJECT_H_
# define AOBJECT_H_

#include "Vector3D.hh"
#include "libgdl_gl-2012.4/include/Game.hpp"

class AObject
{
    public:
	AObject(const newin::Vector3D<GLfloat>& p = newin::Vector3D<GLfloat>(), const newin::Vector3D<GLfloat>& r = newin::Vector3D<GLfloat>(), const newin::Vector3D<GLfloat>& c = newin::Vector3D<GLfloat>(1,1,1)) : _pos(p), _rot(r), _col(c) { }
	virtual void initialize(void) = 0;
	virtual void update(/*gdl::GameClvirtual ock const &, */gdl::Input &) = 0;
	virtual void draw(void) = 0;
	virtual void setPos(const newin::Vector3D<GLfloat>& p) { _pos = p; }
	virtual void setRot(const newin::Vector3D<GLfloat>& r) { _rot = r; }
	virtual void setColor(const newin::Vector3D<GLfloat>& c) { _col = c; }
	virtual newin::Vector3D<GLfloat> getPos() const { return _pos; }
	virtual newin::Vector3D<GLfloat> getRot() const { return _rot; }
	virtual newin::Vector3D<GLfloat> getColor() const { return _col; }
	virtual std::string getIdentifier() const {
	    return _identifier;
	}
	virtual void setIdentifier(const std::string& i) {
	    _identifier = i;
	}
    private:
	std::string _identifier;
    protected:
	newin::Vector3D<GLfloat> _pos;
	newin::Vector3D<GLfloat> _rot;
	newin::Vector3D<GLfloat> _col;
  //  _funcptr();
};


#endif /* !AOBJECT_H_ */
