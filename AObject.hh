#ifndef AOBJECT_H_
# define AOBJECT_H_

#include "Types3D.hh"
#include "libgdl_gl-2012.4/include/Game.hpp"

class AObject
{
    public:
	AObject(void) : position_(0.0f, 0.0f, 0.0f), rotation_(0.0f, 0.0f, 0.0f) { }
	virtual void initialize(void) = 0;
	virtual void update(/*gdl::GameClock const &, */gdl::Input &) = 0;
	virtual void draw(void) = 0;
	virtual void setPos(const newin::Vector3D<GLfloat>&) = 0;
	virtual void setRot(const newin::Vector3D<GLfloat>&) = 0;
	virtual newin::Vector3D<GLfloat> getPos() = 0;
	virtual newin::Vector3D<GLfloat> getRot() = 0;
    protected:
	newin::Vector3D<GLfloat> position_;
	newin::Vector3D<GLfloat> rotation_;
};


#endif /* !AOBJECT_H_ */
