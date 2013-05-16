#include <iostream>
#include <fstream>
#include <string>
#include "Loader.hh"

newin::Loader::Loader(const std::string& f) : _filename(f) {
}

newin::Loader::Loader() : _filename() {
}

newin::Loader::~Loader() {
}

newin::Mesh* newin::Loader::genTri(ShadeProgram* p) {
    std::vector< Vector3D<GLfloat> >* l = new std::vector< Vector3D<GLfloat> >();
    l->push_back(Vector3D<GLfloat>(0.5, 0.5, 0, 0));
    l->push_back(Vector3D<GLfloat>(0.5, -0.5, 0, 0));
    l->push_back(Vector3D<GLfloat>(-0.5, -0.5, 0, 0));
    return new Mesh(l, p);
}

newin::Mesh* newin::Loader::genQuad(ShadeProgram* p) {
    std::vector< Vector3D<GLfloat> >* l = new std::vector< Vector3D<GLfloat> >();
    // v1
    l->push_back(Vector3D<GLfloat>(0.5, 0.5, 0, 0));
    l->push_back(Vector3D<GLfloat>(0.5, -0.5, 0, 0));
    l->push_back(Vector3D<GLfloat>(-0.5, -0.5, 0, 0));
    //v2
    l->push_back(Vector3D<GLfloat>(0.5, 0.5, 0, 0));
    l->push_back(Vector3D<GLfloat>(-0.5, 0.5, 0, 0));
    l->push_back(Vector3D<GLfloat>(-0.5, -0.5, 0, 0));
    return new Mesh(l, p);
}

void newin::Loader::loadMTL(Mesh* m, const std::string& fName) {
    std::fstream f(("resources/" + fName).c_str());
    m->setColor(Vector3D<GLfloat>(0.0, 0.1, 0.1, 1.0));
}

newin::Mesh* newin::Loader::loadOBJ(ShadeProgram* p, const std::string& fName) {
    std::fstream f(("resources/" + fName).c_str());
    std::vector< Vector3D<GLfloat> >* l = new std::vector< Vector3D<GLfloat> >();
    std::vector< Vector3D<GLfloat> >* pure = new std::vector< Vector3D<GLfloat> >();
    std::string tmp;
    std::string mtlfile;
    std::string objectName;
    struct GLvector3f value;
    int index;

    std::cout << "objfile : " << fName << std::endl;
    while (tmp != "mtllib")
	f >> tmp;
    f >> mtlfile;
    std::cout << "mtlfile : " << mtlfile << std::endl;
    f >> tmp;
    f >> objectName;
    std::cout << "object in loading : " << objectName << std::endl;
    f >> tmp;
    while (tmp == "v") {
	f >> value.x;
	f >> value.y;
	f >> value.z;
	pure->push_back(Vector3D<GLfloat>(value.x, value.y, value.z));
	f >> tmp;
    }
    while (tmp != "f") {
	f >> tmp;
    }
    while (tmp == "f") {
	f >> index;
	//std::cout << index << " ";
	l->push_back(pure->at(index - 1));
	f >> index;
	//std::cout << index << " ";
	l->push_back(pure->at(index - 1));
	f >> index;
	//std::cout << index << " ";
	l->push_back(pure->at(index - 1));
	//std::cout << std::endl;
	f >> tmp;
	if (tmp == "usemtl") {
	    f >> tmp;
	    f >> tmp;
	}
    }
    delete pure;
    Mesh * m = new Mesh(l, p);
    loadMTL(m, mtlfile);
    return m;
}
