#include <iostream>
#include <stdlib.h>
#include "glinclude.h"
#include "App.hh"

App::App() : camera_() {
}

App::~App() {
}

void App::initialize(void) {
    window_.create();
    camera_.initialize(_defaultShader,  newin::Vector3D<GLfloat>(0,0,0), newin::Vector3D<GLfloat>(0,0,0));
    GLenum err = glewInit();
    if (err != GLEW_OK)
	std::cerr << "FAIL !" << std::endl;
    newin::Shader v(new std::fstream("defuse_vs.glsl"), GL_VERTEX_SHADER);
    v.compile();
    newin::Shader f(new std::fstream("defuse_fs.glsl"), GL_FRAGMENT_SHADER);
    f.compile();
    _defaultShader = new newin::ShadeProgram(v, f);

    //////////////////////////////////////////////////////////////////////////////
    /// Ajout des objets heritant de AObject dans la liste
    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    /// Appel de la methode initialize des objets
    ////////////////////////////////////////////////////////////////////////////////
    std::list<AObject*>::iterator itb = this->objects_.begin();
    for (; itb != this->objects_.end(); ++itb)
	(*itb)->initialize();
}

void App::update(void) {
    std::list<AObject*>::iterator itb = this->objects_.begin();
    ////////////////////////////////////////////////////////////////////
    /// Appel de la methode update des objets
    //////////////////////////////////////////////////////////////////////
    for (; itb != this->objects_.end(); ++itb)
	(*itb)->update(/*gameClock_,*/input_);
    camera_.update(/*gameClock_,*/ input_);
}

void App::draw(void) {
    //////////////////////////////////////////////////////////////////////////////
    /// Vidage des buffers
    ////////////////////////////////////////////////////////////////////////////////
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.74f, 0.84f, 95.0f, 1.0f);
    glClearDepth(1.0f);
    std::list<AObject*>::iterator itb = this->objects_.begin();
    ////////////////////////////////////////////////////////////////////////////////
    /// Appel de la methode draw des objets
    ////////////////////////////////////////////////////////////////////////////////
    for (; itb != this->objects_.end(); ++itb)
	(*itb)->draw();
    ////////////////////////////////////////////////////////////////////////////////
    /// Affichage du rendu dans la fenetre
    ////////////////////////////////////////////////////////////////////////////////
    this->window_.display();
    //sleep(10);
}

void App::unload(void) {
}
