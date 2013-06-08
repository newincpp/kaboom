#include <iostream>
#include "Mesh.hh"
#include "Player.hh"
#define GLEW_STATIC

newin::Mesh::Mesh(std::vector<Vector3D<GLfloat> >* m, std::vector<Vector3D<GLfloat> >* n) : AObject(), _wireframe(false) {
    _vboID = 0;
    if (m) {
	_verts = Vector3D<GLfloat>::toGLfloatArray(*m);
	_vertexCount = m->size();
    } else {
	_verts = NULL;
	_vertexCount = 0;
    }
    if (n) {
	_normal = Vector3D<GLfloat>::toGLfloatArray(*n);
	_normalCount = n->size();
    } else {
	_normal = NULL;
	_normalCount = 0;
    }
    //checkVertex();
}

newin::Mesh::Mesh(const Mesh& m) : AObject(), _vertexCount(m._vertexCount), _normalCount(m._normalCount), _verts(new GLfloat[m._vertexCount]), _normal(new GLfloat[m._normalCount]), _wireframe(false) {
    for (unsigned int i = 0; i < m._vertexCount; ++i) {
	_verts[i] = m._verts[i];
    }
    for (unsigned int i = 0; i < m._normalCount; ++i) {
	_normal[i] = m._normal[i];
    }
}

newin::Mesh::Mesh() : _s(NULL), _wireframe(false) {
}

void newin::Mesh::checkVertex() const {
    for (unsigned int i = 0 ; i <= (_vertexCount * 3 - 1); i += 3) {
	std::cout << "v:"<< (i + 1) / 3 << " X : = " << _verts[  i  ] << std::endl;
	std::cout << "v:"<< (i + 1) / 3 << " Y : = " << _verts[i + 1] << std::endl;
	std::cout << "v:"<< (i + 1) / 3 << " Z : = " << _verts[i + 2] << std::endl << std::endl;
    }
}

void newin::Mesh::update() const {
    std::cout << "\033[1;32m" << "update vertex in video card buffer" << "\033[0m" << std::endl;

    glBindBuffer(GL_ARRAY_BUFFER, _vboID); // bind (enable) buffer
    // Put data in currently bound buffer
    glBufferData(GL_ARRAY_BUFFER, (_vertexCount) * 3 * sizeof(GLfloat), &_verts[0], GL_STATIC_DRAW);

    //glBindVertexArray(_vboID); // make our VAO the current bound VAO
    glEnableVertexAttribArray(0); // add a new variable for position as location 0 to our VAO

    glBindBuffer(GL_ARRAY_BUFFER, _vboID); // make our VBO the currently bound VBO
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte*)NULL); // map memory for the 0th variable that is the size of 3 floats
    //glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindBuffer (GL_ARRAY_BUFFER, _nboID);
    glEnableVertexAttribArray(1);
    glBufferData (GL_ARRAY_BUFFER, (_normalCount)* sizeof (float), &_normal, GL_STATIC_DRAW);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte*)NULL); // map memory for the 0th variable that is the size of 3 floats
}

void newin::Mesh::setShader(ShadeProgram* s) {
    _s = s;
}

void newin::Mesh::toogleWireframe() {
    _wireframe = !_wireframe;
}

void newin::Mesh::render() {
    if (_s) {
	_s->setVariable("inputColour", Vector3D<GLfloat>(_col.getX(),_col.getY(), _col.getZ(), 1.0));
	_s->setVariable("objTransform", _matrixTransform);
    }
    glBindBuffer(GL_ARRAY_BUFFER, _vboID);
    //glBindVertexArray(_vboID); // make our VAO the current bound VAO
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte*)NULL); // map memory for the 0th variable that is the size of 3 floats
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte*)NULL); // map memory for the 0th variable that is the size of 3 floats

    if (_wireframe == true)
	glDrawArrays(GL_LINE_STRIP, 0, _vertexCount); // draw triangles using VBO points from 0 up to vertexCount
    else
	glDrawArrays(GL_TRIANGLES, 0, _vertexCount); // draw triangles using VBO points from 0 up to vertexCount
    //glBindBuffer(GL_ARRAY_BUFFER, 0);
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
    glTranslatef( _pos.getX(),  _pos.getY(),  _pos.getZ());
    glRotatef(_rot.getZ(), 0, 0, 1);
    glRotatef(_rot.getY(), 0, 1, 0);
    glRotatef(_rot.getX(), 1, 0, 0);
    glGetFloatv(GL_MODELVIEW_MATRIX, _matrixTransform);
    glPopMatrix();
}

//for gdl.....

void newin::Mesh::initialize() {
    glGenBuffers(1, &_vboID);
    glGenBuffers(1, &_nboID);
    update();
}

void newin::Mesh::update(/*gdl::GameClock const &, */ gdl::Input & i) {
  std::vector<Player *>::iterator it;
  if (_play.size() == 0)
	{
	  /*	  if (i.isKeyDown(gdl::Keys::W) == true) {
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
	  if (i.isKeyDown(gdl::Keys::C) == true) {
	    _pos.setY( _pos.getY() - 0.1);
	  }
	  if (i.isKeyDown(gdl::Keys::Space) == true) {
	    _pos.setY( _pos.getY() + 0.1);
	  }
	  if (i.isKeyDown(gdl::Keys::Z) == true) {
	    _wireframe = !_wireframe;
	    }*/
	}
       else
	 {
	   for (it = _play.begin(); it != _play.end(); it++)
	     (*it)->move(i);
	 }
       transform();
}

void newin::Mesh::draw(void) {
    render();
}
