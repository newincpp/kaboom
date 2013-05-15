#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include "Mesh.hh"
#include "Loader.hh"
#include "glinclude.h"
#include "App.hh"

App::App() : _camera(), _defaultLight() {
}

App::~App() {
}

void App::initialize(void) {
    window_.create();
    GLenum err = glewInit();
    if (err != GLEW_OK)
	std::cerr << "FAIL !" << std::endl;
    newin::Shader v(new std::fstream("defuse_vs.glsl"), GL_VERTEX_SHADER);
    newin::Shader f(new std::fstream("defuse_fs.glsl"), GL_FRAGMENT_SHADER);
    try {
	v.compile();
	f.compile();
	_defaultShader = new newin::ShadeProgram(v, f);
    } catch (newin::ShaderException& e) {
	std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
    }
    _camera.initialize(_defaultShader,  newin::Vector3D<GLfloat>(0,0,0), newin::Vector3D<GLfloat>(0,0,0));
    _defaultLight.initialize(_defaultShader, newin::Vector3D<GLfloat>(0.25,0.25,0), newin::Vector3D<GLfloat>(1,1,1));
    //_objects.push_back(newin::Loader().genQuad(_defaultShader));
    _objects.push_back(newin::Loader().loadOBJ(_defaultShader, "test.obj"));
    _objects.push_back(&_defaultLight);
    std::list<AObject*>::iterator itb = _objects.begin();
    for (; itb != _objects.end(); ++itb)
	(*itb)->initialize();
}

void App::update(void) {
    if (input_.isKeyDown(gdl::Keys::Escape)) {
	exit(0);
    }
    std::list<AObject*>::iterator itb = _objects.begin();
    for (; itb != _objects.end(); ++itb)
	(*itb)->update(/*gameClock_,*/input_);
    _camera.update(/*gameClock_,*/ input_);
}

void App::draw(void) {
    _old_time = gameClock_.getElapsedTime();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.74f, 0.84f, 95.0f, 1.0f);
    glClearDepth(1.0f);
    std::list<AObject*>::iterator itb = _objects.begin();
    for (; itb != _objects.end(); ++itb)
	(*itb)->draw();
    window_.display();
    if ((_old_time = (1666.666666 - ((gameClock_.getElapsedTime() - _old_time) * 100000))) > 0)
	usleep(_old_time);
}

void App::unload(void) {
}
