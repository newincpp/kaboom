#include <iostream>
#include "Mesh.hh"
#define GLEW_STATIC

newin::Mesh::Mesh(std::vector<Vector3D<GLfloat> >* m, ShadeProgram* s) : _tset(false), _s(s) , _wireframe(false), _col(Vector3D<GLfloat>(0.1, 0.1, 0.1, 1.0)), _pos(), _rot(), _cam(NULL) {
    _vboID = 0;
    if (m) {
	_verts = Vector3D<GLfloat>::toGLfloatArray(*m);
	int j = 0;
	for (int i = m->size() - 1; i != -1 ; --i) {
	    _verts[j + 0] = m->at(i).getX();
	    _verts[j + 1] = m->at(i).getY();
	    _verts[j + 2] = m->at(i).getZ();
	    j += 3;
	}
	_vertexCount = m->size();
    } else {
	_verts = NULL;
	_vertexCount = 0;
    }
    glGenBuffers(1, &_vboID);
    update();
    //checkVertex();
}

newin::Mesh::Mesh() : _s(NULL), _wireframe(false) {
}

void newin::Mesh::setColor(const Vector3D<GLfloat>& color) {
    _col = color;
}

void newin::Mesh::setPos(const Vector3D<GLfloat>& pos ) {
    _pos = pos;
}

void newin::Mesh::setRot(const Vector3D<GLfloat>& rot) {
    _rot = rot;
}

void newin::Mesh::setTex(const std::string& name) {
    _tex.load("resources/" + name);
    _tset = true;
}

newin::Vector3D<GLfloat> newin::Mesh::getPos() const {
    return _pos;
}

newin::Vector3D<GLfloat> newin::Mesh::getRot() const {
    return _rot;
}


void newin::Mesh::setWorlCam(Camera* c) {
    _cam = c;
}

void newin::Mesh::checkVertex() const {
    for (unsigned int i = 0 ; i <= (_vertexCount * 3 - 1); i += 3) {
	std::cout << "v:"<< (i + 1) / 3 << " X : = " << _verts[  i  ] << std::endl;
	std::cout << "v:"<< (i + 1) / 3 << " Y : = " << _verts[i + 1] << std::endl;
	std::cout << "v:"<< (i + 1) / 3 << " Z : = " << _verts[i + 2] << std::endl << std::endl;
    }
}

void newin::Mesh::update() const {
    std::cout << "\033[1;31m" << "try to updating vbo" << "\033[0m" << std::endl;

    glBindBuffer(GL_ARRAY_BUFFER, _vboID); // bind (enable) buffer
    // Put data in currently bound buffer
    glBufferData(GL_ARRAY_BUFFER, (_vertexCount) * 3 * sizeof(GLfloat), &_verts[0], GL_STATIC_DRAW);

    glBindVertexArray(_vboID); // make our VAO the current bound VAO
    glEnableVertexAttribArray(0); // add a new variable for position as location 0 to our VAO

    glBindBuffer(GL_ARRAY_BUFFER, _vboID); // make our VBO the currently bound VBO
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte*)NULL); // map memory for the 0th variable that is the size of 3 floats
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void newin::Mesh::addVertex(const Vector3D<GLfloat>& n) {
    GLfloat* local = new GLfloat[(_vertexCount + 1) * 3];
    unsigned int i;

    for (i = 0; (i) < (_vertexCount * 3) ; ++i) {
	local[i] = _verts[i];
    }
    ++_vertexCount;
    delete _verts;
    _verts = local;
    _verts[i + 0] = n.getX();
    _verts[i + 1] = n.getY();
    _verts[i + 2] = n.getZ();
    //checkVertex();
    if(glIsBufferARB(_vboID)) {
	glDeleteBuffersARB(1, &_vboID);
    }
    glGenBuffers(1, &_vboID); // regen vbo
    update();
}

void newin::Mesh::setShader(ShadeProgram* s) {
    _s = s;
}

void newin::Mesh::toogleWireframe() {
    _wireframe = !_wireframe;
}

void newin::Mesh::render() {
    //setTextureMatrix();
    if (_s)
	_s->enable();
    else
	glUseProgram(0);
    //update();
    _s->setVariable("objTransform", _matrixTransform);
    _s->setVariable("inputColour", Vector3D<GLfloat>(_col.getX(),_col.getY(), _col.getZ(), 1.0));
    // enable a range of gl rendering options specific to our object
    //if (_tset)
    //_tex.bind();
    glBindBuffer(GL_ARRAY_BUFFER, _vboID);
    glBindVertexArray(_vboID); // make our VAO the current bound VAO
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte*)NULL); // map memory for the 0th variable that is the size of 3 floats
    if (_wireframe == true)
	glDrawArrays(GL_LINE_STRIP, 0, _vertexCount); // draw triangles using VBO points from 0 up to vertexCount
    else
	glDrawArrays(GL_TRIANGLES, 0, _vertexCount); // draw triangles using VBO points from 0 up to vertexCount
    //glBindBuffer(GL_ARRAY_BUFFER, 0);
    //_s->disenable();
}

newin::Mesh::~Mesh() {
    if(glIsBufferARB(_vboID)) {
	glDeleteBuffersARB(1, &_vboID);
    }
    delete _verts;
}

void newin::Mesh::transform() {
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(- _pos.getX(), - _pos.getY(), - _pos.getZ());
    glRotatef(_rot.getZ(), 0, 0, 1);
    glRotatef(_rot.getY(), 0, 1, 0);
    glRotatef(_rot.getX(), 1, 0, 0);
    glGetFloatv(GL_MODELVIEW_MATRIX, _matrixTransform);
    glPopMatrix();
}

//for gdl.....

void newin::Mesh::initialize() {
}

void newin::Mesh::update(/*gdl::GameClock const &, */ gdl::Input & i) {
    if (i.isKeyDown(gdl::Keys::W) == true) {
	_pos.setZ( _pos.getZ() - 0.01);
    }
    if (i.isKeyDown(gdl::Keys::S) == true) {
	_pos.setZ( _pos.getZ() + 0.01);
    }
    if (i.isKeyDown(gdl::Keys::A) == true) {
	_pos.setX( _pos.getX() - 0.01);
    }
    if (i.isKeyDown(gdl::Keys::D) == true) {
	_pos.setX( _pos.getX() + 0.01);
    }
    if (i.isKeyDown(gdl::Keys::Q) == true) {
	_rot.setY( _rot.getY() + 0.1);
    }
    if (i.isKeyDown(gdl::Keys::E) == true) {
	_rot.setY( _rot.getY() - 0.1);
    }
    transform();
}

void newin::Mesh::draw(void) {
    render();
}
