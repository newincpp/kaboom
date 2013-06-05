#include <iostream>
#include <cmath>
#include "Light.hh"

newin::Light::Light(ShadeProgram* prgm, const Vector3D<GLfloat>& p, const Vector3D<GLfloat>& r, const Vector3D<GLfloat>& c) : AObject(p,r,c), _changed(true), _diff(5), _intensity(0.8), _prgm(prgm), _shad(NULL) {
    if (_prgm) {
	internalUpdate();
    }
    _col = c;
}

void newin::Light::initialize(ShadeProgram* prgm, const Vector3D<GLfloat>& p, const Vector3D<GLfloat>& rot, const Vector3D<GLfloat>& c) {
    _pos = p;
    _rot = rot;
    _col = c;
    _prgm = prgm;
    if (!_prgm) {
	throw newin::ShaderException("cannot use light without shader");
    }
    internalUpdate();
    Shader v("shadowMap_vs.glsl", GL_VERTEX_SHADER);
    Shader f("shadowMap_fs.glsl", GL_FRAGMENT_SHADER);

    _shad = new ShadeProgram(v,f);
    _proj.setShader(_shad);
    _modv.setShader(_shad);
    _proj.setShader(_shad);
    initShadowTex();
}

void newin::Light::setShader(ShadeProgram* p) {
    _prgm = p;
    if (!_prgm) {
	throw newin::ShaderException("shader cannot be null");
    }
    internalUpdate();
}

void newin::Light::initialize() {
}

void newin::Light::draw() {
}

void newin::Light::update(/*gdl::GameClock const &, */gdl::Input & i) {
    if (i.isKeyDown(gdl::Keys::I)) {
	_pos.setZ(_pos.getZ() - 0.01);
	_changed = true;
    }
    if (i.isKeyDown(gdl::Keys::K)) {
	_pos.setZ(_pos.getZ() + 0.01);
	_changed = true;
    }
    if (i.isKeyDown(gdl::Keys::J)) {
	_pos.setX(_pos.getX() - 0.01);
	_changed = true;
    }
    if (i.isKeyDown(gdl::Keys::L)) {
	_pos.setX(_pos.getX() + 0.01);
	_changed = true;
    }
    if (i.isKeyDown(gdl::Keys::U)) {
	_pos.setY(_pos.getY() - 0.01);
	_changed = true;
    }
    if (i.isKeyDown(gdl::Keys::O)) {
	_pos.setY(_pos.getY() + 0.01);
	_changed = true;
    }
    if (!_prgm) {
	throw newin::ShaderException("cannot use light without shader");
    }
    if (_changed){
	_changed = false;
	_prgm->setVariable("lightPos", _pos.getX(), _pos.getY(), _pos.getZ());
    }
}

inline void newin::Light::internalUpdate() {
    _prgm->setVariable("lightPos", _pos.getX(), _pos.getY(), _pos.getZ());
    _prgm->setVariable("lightColour", _col.getX(), _col.getY(), _col.getZ());
    _prgm->setVariable("lightDiff", _diff);
    _prgm->setVariable("intensity", _intensity);
}

void newin::Light::setDiff(const int d) {
    _diff = d;
}

void newin::Light::setIntensity(const float i) {
    if (i > 1) {
	std::cout << "warning: intensity > 1 will probably make some shit" << std::endl;
    }
    _intensity = i;
}

float newin::Light::getIntensity() const {
    return _intensity;
}

void newin::Light::initShadowTex() {
    if (!_shad) {
	std::cout << "shader is not set..." << std::endl;
    } else {
	_shad->enable();
    }
    glGenFramebuffers(1, &FramebufferName);
    glGenTextures(1, &depthTexture);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void newin::Light::shadowMap() {
    GLfloat biasMatrix[16] = {
	0.5, 0.0, 0.0, 0.0,
	0.0, 0.5, 0.0, 0.0,
	0.0, 0.0, 0.5, 0.0,
	0.5, 0.5, 0.5, 1.0
    };
    (void) biasMatrix;
    if (_shad) {
	_shad->enable();
    } else {
	std::cout << "warning : shader is not set or has failed to compile" << std::endl;
    }
    //_shad->setVariable("biasMatrix", biasMatrix);

    glBindFramebuffer(GL_FRAMEBUFFER, FramebufferName);
    // Depth texture. Slower than a depth buffer, but you can sample it later in your shader
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, depthTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT16, 1024, 1024, 0, GL_DEPTH_COMPONENT, GL_FLOAT, 0);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    //GLuint depthrenderbuffer;
    //glGenRenderbuffers(1, &depthrenderbuffer);
    //glBindRenderbuffer(GL_RENDERBUFFER, depthrenderbuffer);
    //glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, 1024, 768);
    //glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthrenderbuffer);

    glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, depthTexture, 0);

    glDrawBuffer(GL_NONE); // No color buffer is drawn to.

    // Always check that our framebuffer is ok
    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
	std::cout << "frame Buffer failed" << std::endl;
	return ;
    }
    //_proj.loadProjectionMatrix();
    //_modv.genModelView(_pos, _rot);
    glViewport(0,0,1024,768); // Render on the whole framebuffer, complete from the lower left corner to the upper right
    //glBindFramebuffer(GL_FRAMEBUFFER, 0);
    //    if (_shad)
    //	_shad->disenable();
}

newin::Light::~Light() {
    delete _shad;
}
