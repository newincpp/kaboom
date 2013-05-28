#include <iostream>
#include <cmath>
#include "Camera.hh"

newin::Camera::Camera(ShadeProgram* prgm, const Vector3D<GLfloat>& p, const Vector3D<GLfloat>& r) : _changed(true) ,_pos(p), _rot(r) , _prgm(prgm), _modv(prgm) {
    //calculate();
    //for (unsigned int i = 0; i < 16; ++i) {
    //    _projection[i] = 0;
    //}
    //loadProjectionMatrix();
    //_prgm->setVariable("modelViewMatrix", _modelView);
    _modv.genModelView(_pos, _rot);
    _projv.loadProjectionMatrix();
    //_prgm->setVariable("projectionMatrix", _projection);
}

newin::Camera::Camera() {
}

newin::Camera::~Camera() {
}

void newin::Camera::initialize(ShadeProgram* prgm, const Vector3D<GLfloat>& p, const Vector3D<GLfloat>& r) {
    _pos = p;
    _rot = r;
    _prgm = prgm;
    _changed = true;
    if (_prgm == NULL) {
	throw ShaderException("progam is not set...");
    }
    _modv.setShader(_prgm);
    _projv.setShader(_prgm);
    _modv.genModelView(_pos, _rot);
    _projv.loadProjectionMatrix();
}

void newin::Camera::update(/*gdl::GameClock const & gameClock,*/ gdl::Input & i) {
    if (i.isKeyDown(gdl::Keys::Numpad4) == true) {
	_pos.setX( _pos.getX() + 0.01);
	_changed = true;
    }
    if (i.isKeyDown(gdl::Keys::Numpad6) == true) {
	_pos.setX( _pos.getX() - 0.01);
	_changed = true;
    }
    if (i.isKeyDown(gdl::Keys::Numpad8) == true) {
	_pos.setZ( _pos.getZ() - 0.01);
	_changed = true;
    }
    if (i.isKeyDown(gdl::Keys::Numpad5) == true) {
	_pos.setZ( _pos.getZ() + 0.01);
	_changed = true;
    }
    if (i.isKeyDown(gdl::Keys::Add) == true) {
	_pos.setY( _pos.getY() + 0.01);
	_changed = true;
    }
    if (i.isKeyDown(gdl::Keys::Subtract) == true) {
	_pos.setY( _pos.getY() - 0.01);
	_changed = true;
    }
    if (i.isKeyDown(gdl::Keys::Numpad7) == true) {
	_rot.setY(_rot.getY() + 0.1);
	_changed = true;
    }
    if (i.isKeyDown(gdl::Keys::Numpad9) == true) {
	_rot.setY(_rot.getY() - 0.1);
	_changed = true;
    }
    if (_changed){
	_changed = false;
	_modv.genModelView(_pos, _rot);
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

void newin::Camera::renderMode() {
    _prgm->enable();
}

void newin::Camera::endRenderMode() {
    _prgm->disenable();
}

newin::mat4<GLfloat> newin::Camera::getModelViewMatrix() { // cannot be const because return non const pointer
    return _modv;
}

newin::mat4<GLfloat> newin::Camera::getProjectionMatrix() { // cannot be const because return non const pointer
    return _projv;
}
