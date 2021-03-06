#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <unistd.h>
#include <exception>
#include "Loader.hh"
#include "Scene.hh"

newin::SceneMgr::SceneMgr() :  _height(__DHEIGHT), _width(__DWIDTH), _camera(),  _defaultShader(NULL), _contextEnabed(false) {
    newin::Light* defaultLight = new newin::Light();
    _lights.push_back(defaultLight);
//    _lights.push_back(defaultLight);
}

newin::SceneMgr::~SceneMgr() {
}

void newin::SceneMgr::initialize(void) {
    window_.setWidth(_width);
    window_.setHeight(_height);
    window_.setTitle("bomberman !");
    window_.create();
    glViewport(0, 0, _width, _height);
    GLenum err = glewInit();
    if (err != GLEW_OK)
	std::cerr << "FAIL !" << std::endl;
    try {
	newin::Shader v("defuse_vs.glsl", GL_VERTEX_SHADER);
	newin::Shader f("defuse_fs.glsl", GL_FRAGMENT_SHADER);
	_defaultShader = new newin::ShadeProgram(v, f);
    } catch (newin::ShaderException& e) {
	std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
    }
    _contextEnabed = true;
    _camera.initialize(_defaultShader,  _camera.getPos(), _camera.getRot());

    for (unsigned int i = 0; i != _lights.size(); ++i) {
	_lights[i]->initialize(_defaultShader, _lights[i]->getPos(), _lights[i]->getRot(), newin::Vector3D<GLfloat>(1, 1, 1), i);
    }
    _defaultShader->setVariable("numlight", (int)_lights.size());

    std::list<AObject*>::iterator itb = _objects.begin();
    for (; itb != _objects.end(); ++itb) {
	(*itb)->initialize();
	((Mesh*)(*itb))->setShader(_defaultShader);
    }
}

void newin::SceneMgr::update(void) {
    if (input_.isKeyDown(gdl::Keys::Escape)) {
	window_.close();
    }
    for (unsigned int i = 0; i != _lights.size(); ++i)
	_lights[i]->update(gameClock_, input_);
    _camera.update(gameClock_, input_);
    std::list<AObject*>::iterator itb = _objects.begin();
    for (; itb != _objects.end(); ++itb)
	(*itb)->update(gameClock_,input_);
}

void newin::SceneMgr::draw(void) {
    _old_time = gameClock_.getElapsedTime();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST); // enable depth-testing
    glDepthMask(GL_TRUE); // turn back on
    glDepthFunc(GL_LESS);
    glCullFace(GL_FRONT);
    glClearDepth(1.0f);

    std::list<AObject*>::iterator itb = _objects.begin();
    /*
    //render shadow
    _defaultLight.shadowMap();
    for (; itb != _objects.end(); ++itb) {
    (*itb)->draw();
    }
    */
    //render object
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    _camera.renderMode();
    itb = _objects.begin();
    for (; itb != _objects.end(); ++itb) {
	if ((*itb)->renderStatus())
	    (*itb)->draw();
    }
    _camera.endRenderMode();
    window_.display();
    if ((_old_time = (1666.666666 - ((gameClock_.getElapsedTime() - _old_time) * 100000))) > 0)
	usleep(_old_time);
}

void newin::SceneMgr::unload(void) {
    delete _defaultShader;
}

std::list<AObject*> newin::SceneMgr::getObjectList() const {
    return _objects;
}


newin::Camera* newin::SceneMgr::getCam() {
    return &_camera;
}


void newin::SceneMgr::setCamPos(const newin::Vector3D<GLfloat>& p) {
    _camera.setPos(p);
}

std::vector<newin::Light*> newin::SceneMgr::getLights() {
    return _lights;
}

newin::Light* newin::SceneMgr::getLight(unsigned int index) {
    std::cout << "index : " << index << "size " << _lights.size() << std::endl;
    return _lights[index];
}

unsigned int newin::SceneMgr::addLight(newin::Light lightModel) {
    newin::Light* nlight;
    if (_contextEnabed) {
	nlight = new newin::Light(_defaultShader, lightModel.getPos(), lightModel.getRot(), lightModel.getColor(), _lights.size());
	nlight->initialize(_defaultShader, lightModel.getPos(), lightModel.getRot(), lightModel.getColor(), _lights.size());
	nlight->setDiff(lightModel.getDiff());
	nlight->setIntensity(lightModel.getIntensity());
	_defaultShader->setVariable("numlight", (int)_lights.size());
    } else {
	nlight = new newin::Light(NULL, lightModel.getPos(), lightModel.getRot(), lightModel.getColor(), _lights.size());
	nlight->setDiff(lightModel.getDiff());
	nlight->setIntensity(lightModel.getIntensity());
    }
    _lights.push_back(nlight);
    std::cout << "len after " << _lights.size() << std::endl;
    std::cout << "len returned " << _lights.size() - 1 << std::endl;
    return _lights.size() - 1;
}

AObject* newin::SceneMgr::addModel(const std::string& name, const std::string& identifier) {
    newin::Mesh* tmp = newin::Loader().loadOBJ(name);
    if (_contextEnabed){
	tmp->initialize();
	tmp->setShader(_defaultShader);
    }
    _objects.push_back(tmp);
    tmp->setIdentifier(identifier);
    std::cout << "shade added" << std::endl;
    return tmp;
}

AObject* newin::SceneMgr::getModel(const std::string& id) {
    std::list<AObject*>::iterator itb = _objects.begin();
    for (; itb != _objects.end(); ++itb) {
	if ((*itb)->getIdentifier() == id) {
	    return *itb;
	}
    }
    return NULL;
}

void newin::SceneMgr::delModel(const std::string& id) {
    std::list<AObject*>::iterator itb = _objects.begin();
    for (; itb != _objects.end(); ++itb) {
	if ((*itb)->getIdentifier() == id) {
	    delete (*itb);
	}
    }
}
