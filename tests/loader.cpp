#include <string>
#include "loader.hh"

newin::Loader::Loader(const std::string& f) : _filename(f) {
}

newin::Loader::Loader() : _filename() {
}

newin::Loader::~Loader() {
}

std::vector< newin::Vector3D<GLfloat> >* newin::Loader::genMesh() {
    std::vector< Vector3D<GLfloat> >* l = new std::vector< Vector3D<GLfloat> >();
    return l;
}

std::vector< newin::Vector3D<GLfloat> >* newin::Loader::genTri() {
    std::vector< Vector3D<GLfloat> >* l = new std::vector< Vector3D<GLfloat> >();
    l->push_back(Vector3D<GLfloat>(0.5, 0.5, 0, 0));
    l->push_back(Vector3D<GLfloat>(0.5, -0.5, 0, 0));
    l->push_back(Vector3D<GLfloat>(-0.5, -0.5, 0, 0));

    return l;
}

std::vector< newin::Vector3D<GLfloat> >* newin::Loader::genQuad() {
    std::vector< Vector3D<GLfloat> >* l = new std::vector< Vector3D<GLfloat> >();
    // v1
    l->push_back(Vector3D<GLfloat>(0.5, 0.5, 0, 0));
    l->push_back(Vector3D<GLfloat>(0.5, -0.5, 0, 0));
    l->push_back(Vector3D<GLfloat>(-0.5, -0.5, 0, 0));
    //v2
    l->push_back(Vector3D<GLfloat>(0.5, 0.5, 0, 0));
    l->push_back(Vector3D<GLfloat>(-0.5, 0.5, 0, 0));
    l->push_back(Vector3D<GLfloat>(-0.5, -0.5, 0, 0));
    return l;
}

std::vector< newin::Vector3D<GLfloat> >* newin::Loader::loadOBJ() {
}
