#include <iostream>
#include <cmath>
#include "Camera.hh"

newin::Camera::Camera(ShadeProgram* prgm, const Vector3D<GLfloat>& p, const Vector3D<GLfloat>& r) : _changed(true) ,_pos(p), _rot(r) , _prgm(prgm) {
    calculate();
    for (unsigned int i = 0; i < 16; ++i) {
	_projection[i] = 0;
    }
   loadProjectionMatrix();
    _prgm->setVariable("modelViewMatrix", _modelView);
    _prgm->setVariable("projectionMatrix", _projection);
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
    calculate();
    loadProjectionMatrix();
    _prgm->setVariable("modelViewMatrix", _modelView);
    _prgm->setVariable("projectionMatrix", _projection);
}

void newin::Camera::calculate() {
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(_rot.getZ(), 0, 0, 1);
    glRotatef(_rot.getY(), 0, 1, 0);
    glRotatef(_rot.getX(), 1, 0, 0);
    glTranslatef(- _pos.getX(), - _pos.getY(), - _pos.getZ());
    glGetFloatv(GL_MODELVIEW_MATRIX, _modelView);
    glPopMatrix();
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
	_pos.setY( _pos.getY() - 0.01);
	_changed = true;
    }
    if (i.isKeyDown(gdl::Keys::Numpad5) == true) {
	_pos.setY( _pos.getY() + 0.01);
	_changed = true;
    }
    if (i.isKeyDown(gdl::Keys::Add) == true) {
	_pos.setZ( _pos.getZ() - 0.01);
	_changed = true;
    }
    if (i.isKeyDown(gdl::Keys::Subtract) == true) {
	_pos.setZ( _pos.getZ() + 0.01);
	_changed = true;
    }
    if (_changed){
	_changed = false;
	calculate();
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

void newin::Camera::loadProjectionMatrix(float fov, float aspect, float znear, float zfar)
{
    float xymax = znear * tan(fov);
    float ymin = -xymax;
    float xmin = -xymax;
    float width = xymax - xmin;
    float height = xymax - ymin;
    float depth = zfar - znear;
    float q = -(zfar + znear) / depth;
    float qn = -2 * (zfar * znear) / depth;
    float w = 2 * znear / width;
    w = w / aspect;
    float h = 2 * znear / height;

    _projection[0]  = w;
    _projection[1]  = 0;
    _projection[2]  = 0;
    _projection[3]  = 0;
    _projection[4]  = 0;
    _projection[5]  = h;
    _projection[6]  = 0;
    _projection[7]  = 0;
    _projection[8]  = 0;
    _projection[9]  = 0;
    _projection[10] = q;
    _projection[11] = -1;
    _projection[12] = 0;
    _projection[13] = 0;
    _projection[14] = qn;
    _projection[15] = 0;
}
