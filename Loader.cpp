#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Loader.hh"

newin::Loader::Loader(const std::string& f) : _filename(f) {
}

newin::Loader::Loader() : _filename() {
}

newin::Loader::~Loader() {
}

newin::Mesh* newin::Loader::genTri() {
    std::vector< Vector3D<GLfloat> >* l = new std::vector< Vector3D<GLfloat> >();
    l->push_back(Vector3D<GLfloat>(0.5, 0.5, 0, 0));
    l->push_back(Vector3D<GLfloat>(0.5, -0.5, 0, 0));
    l->push_back(Vector3D<GLfloat>(-0.5, -0.5, 0, 0));
    return new Mesh(l, NULL);
}

newin::Mesh* newin::Loader::genQuad() {
    std::vector< Vector3D<GLfloat> >* l = new std::vector< Vector3D<GLfloat> >();
    // v1
    l->push_back(Vector3D<GLfloat>(0.5, 0.5, 0, 0));
    l->push_back(Vector3D<GLfloat>(0.5, -0.5, 0, 0));
    l->push_back(Vector3D<GLfloat>(-0.5, -0.5, 0, 0));
    //v2
    l->push_back(Vector3D<GLfloat>(0.5, 0.5, 0, 0));
    l->push_back(Vector3D<GLfloat>(-0.5, 0.5, 0, 0));
    l->push_back(Vector3D<GLfloat>(-0.5, -0.5, 0, 0));
    return new Mesh(l, NULL);
}

void newin::Loader::loadMTL(Mesh* m, const std::string& fName) {
    std::fstream f(("resources/" + fName).c_str());
    m->setColor(Vector3D<GLfloat>(0.1, 0.1, 0.1, 1.0));
}

newin::Mesh* newin::Loader::loadOBJ(const std::string& fName) {
    std::fstream f(("resources/" + fName).c_str());
    {
	std::map<std::string,Mesh*>::iterator tmp = _meshdb.find("fName");
	if (tmp != _meshdb.end()) {
	    return new Mesh(*(tmp->second));
	}
    }
    std::vector< Vector3D<GLfloat> >* vertex= new std::vector< Vector3D<GLfloat> >();
    std::vector< Vector3D<GLfloat> >* pure = new std::vector< Vector3D<GLfloat> >();
    std::vector< Vector3D<GLfloat> >* n = new std::vector< Vector3D<GLfloat> >();
    std::vector< Vector3D<GLfloat> >* normal = new std::vector< Vector3D<GLfloat> >();
    std::string tmp;
    std::string mtlfile;
    std::string objectName;
    struct GLvector3f value;

    std::cout << "objfile : " << fName << std::endl;
    if (!f.is_open()) {
	std::cout << "failed to open file" << std::endl;
	return new Mesh(NULL,NULL);
    }
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
    while (tmp == "vn") {
	f >> value.x;
	f >> value.y;
	f >> value.z;
	n->push_back(Vector3D<GLfloat>(value.x, value.y, value.z));
	f >> tmp;
    }
    orderInFaceList(vertex, pure, normal, n, f);
    delete pure;
    f.close();
    Mesh* m = new Mesh(vertex, normal);
    loadMTL(m, mtlfile);
    delete vertex;
    delete n;
    return m;
}

void newin::Loader::orderInFaceList(std::vector< Vector3D<GLfloat> >* vert, std::vector< Vector3D<GLfloat> >* pvert,
	std::vector< Vector3D<GLfloat> >* nor, std::vector< Vector3D<GLfloat> >* pnor,
	std::fstream& f) {
    std::string tmp;
    std::string svert;
    std::string snormal;
    unsigned int delimitter;

    while (!f.eof()) {
	while (!f.eof() && tmp != "f") {
	    f >> tmp;
	}
	if (!f.eof()) {
	    for (unsigned int i = 0; i < 3; ++i) {
		f >> tmp;
		delimitter = tmp.find("//");
		svert = tmp.substr(0, delimitter);
		snormal = tmp.substr(delimitter + 2);
		vert->push_back(pvert->at(std::atoi(svert.c_str()) - 1));
		nor->push_back(pnor->at(std::atoi(snormal.c_str()) - 1));
	    }
	    f >> tmp;
	}
    }
}
