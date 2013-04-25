#include "camera.hh"

newin::Camera::Camera(Vector3D<GLfloat> p, Vector3D<GLfloat> r) : _pos(p), _rot(r) {
    (void)projMatrix;
    (void)viewMatrix;
}

newin::Camera::~Camera() {
}
