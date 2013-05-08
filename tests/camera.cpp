#include "camera.hh"

newin::Camera::Camera(ShadeProgram* prgm, const Vector3D<GLfloat>& p, const Vector3D<GLfloat>& r) : _changed(true), _pos(p), _rot(r) , _prgm(prgm) {
    update();
}

newin::Camera::~Camera() {
}

newin::Vector3D<GLfloat> newin::Camera::getPos() const {
    return _pos;
}

newin::Vector3D<GLfloat> newin::Camera::getRot() const {
    return _rot;
}

void newin::Camera::update() {
    if (!_changed)
	return;
    else {
	_changed = false;
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(_pos.getX(), _pos.getY(), _pos.getZ());
	glGetFloatv(GL_MODELVIEW_MATRIX, _modelView);
	glPopMatrix();
	_prgm->setVariable("modelViewMatrix", _modelView);
	//_prgm->setVariable("transCam", _pos.getX(), _pos.getY(), _pos.getW(), _pos.getZ());
	//_prgm->setVariable("rotCam", _rot);
    }
}

void newin::Camera::setPos(const Vector3D<GLfloat>& p) {
    _pos = p;
    _changed = true;
    update();
}

void newin::Camera::setRot(const Vector3D<GLfloat>& r) {
    _rot = r;
    _changed = true;
    update();
}
