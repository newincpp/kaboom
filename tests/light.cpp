#include "iostream"
#include "light.hh"

newin::Light::Light(ShadeProgram* prgm, const Vector3D<GLfloat>& p, const Vector3D<GLfloat>& d) : _pos(p) , _diff(d), _prgm(prgm){
    std::cout << "X : " << _diff.getX() << std::endl
    << "Y : " << _diff.getY() << std::endl
    << "Z : " << _diff.getZ() << std::endl
    << "W : " << _diff.getW() << std::endl;
    _prgm->setVariable("lightPos", _pos.getX(), _pos.getY(), _pos.getZ());
    _prgm->setVariable("lightDiff", _diff.getX(), _diff.getY(), _diff.getZ());
}

newin::Light::~Light() {
}
