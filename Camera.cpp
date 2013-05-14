#include <iostream>
#include "Camera.hh"

newin::Camera::Camera(ShadeProgram* prgm, const Vector3D<GLfloat>& p, const Vector3D<GLfloat>& r) : _changed(true) ,_pos(p), _rot(r) , _prgm(prgm) {
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(_pos.getX(), _pos.getY(), _pos.getZ());
    glGetFloatv(GL_MODELVIEW_MATRIX, _modelView);
    glPopMatrix();
    _prgm->setVariable("modelViewMatrix", _modelView);
}

newin::Camera::Camera() {
}

newin::Camera::~Camera() {
}

void newin::Camera::initialize(ShadeProgram* prgm, const Vector3D<GLfloat>& p, const Vector3D<GLfloat>& r) {
    _pos = p;
    _rot = r;
    _prgm = prgm;
    if (_prgm == NULL) {
	throw ShaderException("progam is not set...");
    }
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(_pos.getX(), _pos.getY(), _pos.getZ());
    glGetFloatv(GL_MODELVIEW_MATRIX, _modelView);
    glPopMatrix();
    _prgm->setVariable("modelViewMatrix", _modelView);
}

void newin::Camera::update(/*gdl::GameClock const & gameClock,*/ gdl::Input & i) {
    if (i.isKeyDown(gdl::Keys::A) == true) {
	_pos.setX( _pos.getX() - 0.01);
	_changed = true;
    }
    if (i.isKeyDown(gdl::Keys::D) == true) {
	_pos.setX( _pos.getX() + 0.01);
	_changed = true;
    }
    if (i.isKeyDown(gdl::Keys::W) == true) {
	_pos.setY( _pos.getY() + 0.01);
	_changed = true;
    }
    if (i.isKeyDown(gdl::Keys::S) == true) {
	_pos.setY( _pos.getY() - 0.01);
	_changed = true;
    }
    if (i.isKeyDown(gdl::Keys::Up) == true) {
	_pos.setZ( _pos.getZ() - 0.01);
	_changed = true;
    }
    if (i.isKeyDown(gdl::Keys::Down) == true) {
	_pos.setZ( _pos.getZ() + 0.01);
	_changed = true;
    }
    if (!_changed)
	return;
    else {
	_changed = false;
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(_pos.getX(), _pos.getY(), _pos.getZ());
	glRotatef(_rot.getX(), _rot.getY(), _rot.getZ(), _rot.getW());
	glGetFloatv(GL_MODELVIEW_MATRIX, _modelView);
	glPopMatrix();
	_prgm->setVariable("modelViewMatrix", _modelView);
    }
}

newin::Vector3D<GLfloat> newin::Camera::getPos() const {
    return _pos;
}

newin::Vector3D<GLfloat> newin::Camera::getRot() const {
    return _rot;
}

void newin::Camera::setPos(const Vector3D<GLfloat>& p) {
    _changed = true;
    _pos = p;
}

void newin::Camera::setRot(const Vector3D<GLfloat>& r) {
    _changed = true;
    _rot = r;
}
