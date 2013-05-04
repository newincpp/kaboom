#include "Camera.hh"

newin::Camera::Camera(ShadeProgram* prgm, const Vector3D<GLfloat>& p, const Vector3D<GLfloat>& r) : _pos(p), _rot(r) , _prgm(prgm) {
    _prgm->setVariable("transCam", _pos.getX(), _pos.getY(), _pos.getW(), _pos.getZ());
    _prgm->setVariable("rotCam", _rot);
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
    _prgm->setVariable("transCam", _pos.getX(), _pos.getY(), _pos.getW(), _pos.getZ());
    _prgm->setVariable("rotCam", _rot);
}

void newin::Camera::update(/*gdl::GameClock const & gameClock,*/ gdl::Input & input) {
    (void) input;
    _prgm->setVariable("transCam", _pos.getX(), _pos.getY(), _pos.getW(), _pos.getZ());
//    _prgm->setVariable("rotCam", _rot);
}

newin::Vector3D<GLfloat> newin::Camera::getPos() const {
    return _pos;
}

newin::Vector3D<GLfloat> newin::Camera::getRot() const {
    return _rot;
}

void newin::Camera::setPos(const Vector3D<GLfloat>& p) {
    _pos = p;
    _prgm->setVariable("transCam", _pos.getX(), _pos.getY(), _pos.getW(), _pos.getZ());
}

void newin::Camera::setRot(const Vector3D<GLfloat>& r) {
    _rot = r;
    _prgm->setVariable("rotCam", _rot);
}
