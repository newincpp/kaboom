#ifndef AOBJECT_H_
# define AOBJECT_H_

#include "Vector3D.hh"
#include "libgdl_gl-2012.4/include/Game.hpp"

class AObject
{
    public:
	AObject(const newin::Vector3D<GLfloat>& p = newin::Vector3D<GLfloat>(), const newin::Vector3D<GLfloat>& r = newin::Vector3D<GLfloat>()) : _pos(p), _rot(r) { }
	virtual void initialize(void) = 0;
	virtual void update(/*gdl::GameClock const &, */gdl::Input &) = 0;
	virtual void draw(void) = 0;
	virtual void setPos(const newin::Vector3D<GLfloat>&) = 0;
	virtual void setRot(const newin::Vector3D<GLfloat>&) = 0;
	virtual newin::Vector3D<GLfloat> getPos() const = 0;
	virtual newin::Vector3D<GLfloat> getRot() const = 0;
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

};


#endif /* !AOBJECT_H_ */
