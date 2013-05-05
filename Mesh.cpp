#include <iostream>
#include "Mesh.hh"

newin::Mesh::Mesh(const std::vector<Vector3D<GLfloat> >* m, ShadeProgram* s) : _s(s) , _wireframe(false), _col(Vector3D<GLfloat>(0.0, 0.4, 0.25, 1.0)) {
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
    glBufferData(GL_ARRAY_BUFFER, (_vertexCount) * 3 * sizeof(GLfloat), &_verts[0], GL_DYNAMIC_DRAW);

    glBindVertexArray(_vboID); // make our VAO the current bound VAO
    glEnableVertexAttribArray(0); // add a new variable for position as location 0 to our VAO

    glBindBuffer(GL_ARRAY_BUFFER, _vboID); // make our VBO the currently bound VBO
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte*)NULL); // map memory for the 0th variable that is the size of 3 floats
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
    //checkVertex();
}

void newin::Mesh::render() {
    if (_s)
	_s->enable();
    else
	glUseProgram(0);
    _s->setVariable("inputColour", Vector3D<GLfloat>(_col.getX(),_col.getY(), _col.getZ(), 1.0));
    // enable a range of gl rendering options specific to our object
    glEnable(GL_DEPTH_TEST); // enable depth-testing
    glDepthMask(GL_TRUE); // turn back on
    glDepthFunc(GL_LESS);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);
    glBindBuffer(GL_ARRAY_BUFFER, _vboID); // bind (enable) buffer
    if (_wireframe == true)
	glDrawArrays(GL_LINE_STRIP, 0, _vertexCount); // draw triangles using VBO points from 0 up to vertexCount
    else
	glDrawArrays(GL_TRIANGLE_STRIP, 0, _vertexCount); // draw triangles using VBO points from 0 up to vertexCount
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    _s->disenable();
}

newin::Mesh::~Mesh() {
    if(glIsBufferARB(_vboID)) {
	glDeleteBuffersARB(1, &_vboID);
    }
    delete _verts;
}


//for gdl.....

void newin::Mesh::initialize() {
}

void newin::Mesh::update(/*gdl::GameClock const &, */ gdl::Input & i) {
    (void)i;
}

void newin::Mesh::draw(void) {
    render();
}
