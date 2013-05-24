#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include "Loader.hh"
#include "App.hh"
#include <unistd.h>

App::App() : _camera(), _defaultLight() {
}

App::~App() {
}

void App::initialize(void) {
    window_.setWidth(800);
    window_.setHeight(600);
    window_.create();
    window_.setTitle("bomberman !");
    GLenum err = glewInit();
    if (err != GLEW_OK)
	std::cerr << "FAIL !" << std::endl;
    newin::Shader v(new std::fstream("defuse_vs.glsl"), GL_VERTEX_SHADER);
    newin::Shader f(new std::fstream("defuse_fs.glsl"), GL_FRAGMENT_SHADER);
    newin::Shader g(new std::fstream("default_gs.glsl"), GL_GEOMETRY_SHADER);
    try {
	v.compile();
	f.compile();
	g.compile();
	_defaultShader = new newin::ShadeProgram(v, f, g);
    } catch (newin::ShaderException& e) {
	std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
    }
    _camera.initialize(_defaultShader,  newin::Vector3D<GLfloat>(0, 1, 5), newin::Vector3D<GLfloat>(0, 0, 0));
    _defaultLight.initialize(_defaultShader, newin::Vector3D<GLfloat>(0.25, 0.25, 0), newin::Vector3D<GLfloat>(1,1,1), newin::Vector3D<GLfloat>(0.5, 0.5, 0.5));
    _objects.push_back(newin::Loader().loadOBJ(_defaultShader, "plane.obj"));
    ((newin::Mesh*)_objects.back())->setColor(newin::Vector3D<GLfloat>(0, 0.5, 0));
    ((newin::Mesh*)_objects.back())->setWorlCam(&_camera);
    _objects.push_back(newin::Loader().loadOBJ(_defaultShader, "test.obj"));
    _objects.back()->setPos(newin::Vector3D<GLfloat>(0, -1, 0));
    _objects.back()->setRot(newin::Vector3D<GLfloat>(0, 30, 0));
    ((newin::Mesh*)_objects.back())->setWorlCam(&_camera);

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
    glClearColor(0.05f, 0.05, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST); // enable depth-testing
    glDepthMask(GL_TRUE); // turn back on
    glDepthFunc(GL_LESS);
    glClearDepth(1.0f);
    std::list<AObject*>::iterator itb = _objects.begin();
for (; itb != _objects.end(); ++itb)
	(*itb)->draw();
    window_.display();
    if ((_old_time = (1666.666666 - ((gameClock_.getElapsedTime() - _old_time) * 100000))) > 0)
	usleep(_old_time);
}

void App::unload(void) {
    delete _defaultShader;
}
