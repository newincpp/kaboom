#include <iostream>
#include "Light.hh"

newin::Light::Light(ShadeProgram* prgm, const Vector3D<GLfloat>& p, const Vector3D<GLfloat>& d) : _changed(true), _pos(p) , _diff(d), _spec(), _prgm(prgm){
    if (_prgm) {
	_prgm->setVariable("lightPos", _pos.getX(), _pos.getY(), _pos.getZ());
	_prgm->setVariable("lightDiff ", _diff.getX(), _diff.getY(), _diff.getZ());
	_prgm->setVariable("specular", _spec.getX(), _spec.getY(), _spec.getZ());
    }
}

void newin::Light::initialize(ShadeProgram* prgm, const Vector3D<GLfloat>& p, const Vector3D<GLfloat>& d) {
    _pos = p;
    _diff = d;
    _prgm = prgm;
    if (!_prgm) {
	throw newin::ShaderException("cannot use light without shader");
    }
    _prgm->setVariable("lightPos", _pos.getX(), _pos.getY(), _pos.getZ());
    _prgm->setVariable("lightDiff", _diff.getX(), _diff.getY(), _diff.getZ());
    _prgm->setVariable("specular", _spec.getX(), _spec.getY(), _spec.getZ());
}

void newin::Light::setShader(ShadeProgram* p) {
    _prgm = p;
    if (!_prgm) {
	throw newin::ShaderException("shader cannot be null");
    }
    _prgm->setVariable("lightPos", _pos.getX(), _pos.getY(), _pos.getZ());
    _prgm->setVariable("lightDiff", _diff.getX(), _diff.getY(), _diff.getZ());
    _prgm->setVariable("specular", _spec.getX(), _spec.getY(), _spec.getZ());
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
    if (!_changed)
	return;
    else {
	_changed = false;
	_prgm->setVariable("lightPos", _pos.getX(), _pos.getY(), _pos.getZ());
	_prgm->setVariable("lightDiff", _diff.getX(), _diff.getY(), _diff.getZ());
	_prgm->setVariable("specular", _spec.getX(), _spec.getY(), _spec.getZ());
    }
}

void newin::Light::setPos(const newin::Vector3D<GLfloat>& p) {
    _pos = p;
}

void newin::Light::setDiff(const newin::Vector3D<GLfloat>& d) {
    _diff = d;
}

void newin::Light::setSpecular(const newin::Vector3D<GLfloat>& s) {
    _spec = s;
}

newin::Vector3D<GLfloat> newin::Light::getPos() {
    return _pos;
}

newin::Vector3D<GLfloat> newin::Light::getDiff() {
    return _diff;
}

newin::Vector3D<GLfloat> newin::Light::getSpecular() {
    return _spec;
}

newin::Light::~Light() {
}
