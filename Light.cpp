#include <iostream>
#include "Light.hh"

newin::Light::Light(ShadeProgram* prgm, const Vector3D<GLfloat>& p, const Vector3D<GLfloat>& lookat, const Vector3D<GLfloat>& c) : _changed(true), _pos(p), _lookat(lookat), _color(c), _prgm(prgm) {
    if (_prgm) {
	_prgm->setVariable("lightPos", _pos.getX(), _pos.getY(), _pos.getZ());
	_prgm->setVariable("lightColour", _color);
	_prgm->setVariable("lightLookAt", _lookat.getX(), _lookat.getY(), _lookat.getZ());
    }
}

void newin::Light::initialize(ShadeProgram* prgm, const Vector3D<GLfloat>& p, const Vector3D<GLfloat>& lookat, const Vector3D<GLfloat>& c) {
    _pos = p;
    _lookat = lookat;
    _color = c;
    _prgm = prgm;
    if (!_prgm) {
	throw newin::ShaderException("cannot use light without shader");
    }
    _prgm->setVariable("lightPos", _pos.getX(), _pos.getY(), _pos.getZ());
    _prgm->setVariable("lightColour", _color.getX(), _color.getY(), _color.getZ());
    _prgm->setVariable("lightLookAt", _lookat.getX(), _lookat.getY(), _lookat.getZ());
    _prgm->setVariable("intensity", 0.4f);
}

void newin::Light::setShader(ShadeProgram* p) {
    _prgm = p;
    if (!_prgm) {
	throw newin::ShaderException("shader cannot be null");
    }
    _prgm->setVariable("lightPos", _pos.getX(), _pos.getY(), _pos.getZ());
    _prgm->setVariable("lightColour", _color.getX(), _color.getY(), _color.getZ());
    _prgm->setVariable("lightLookAt", _lookat.getX(), _lookat.getY(), _lookat.getZ());
}

void newin::Light::initialize() {
}

void newin::Light::draw() {
}

void newin::Light::update(/*gdl::GameClock const &, */gdl::Input & i) {
    (void) i;
    if (!_prgm) {
	throw newin::ShaderException("cannot use light without shader");
    }
    if (_changed){
	_changed = false;
	_prgm->setVariable("lightPos", _pos.getX(), _pos.getY(), _pos.getZ());
	_prgm->setVariable("lightColour", _color.getX(), _color.getY(), _color.getZ());
	_prgm->setVariable("lightLookAt", _lookat.getX(), _lookat.getY(), _lookat.getZ());
    }
}

void newin::Light::setPos(const newin::Vector3D<GLfloat>& p) {
    _pos = p;
}

void newin::Light::setRot(const newin::Vector3D<GLfloat>& r) {
    (void) r;
}

void newin::Light::setColor(const newin::Vector3D<GLfloat>& c) {
    _color = c;
}

newin::Vector3D<GLfloat> newin::Light::getPos() const {
    return _pos;
}

newin::Vector3D<GLfloat> newin::Light::getRot() const {
    return Vector3D<GLfloat>();
}
newin::Vector3D<GLfloat> newin::Light::getColor() const {
    return _color;
}
newin::Light::~Light() {
}
