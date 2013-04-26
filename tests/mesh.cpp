#include <iostream>
#include "mesh.hh"

newin::Mesh::Mesh(const std::vector<Vector3D<GLfloat> >& m) : _s(NULL) {
    _verts = Vector3D<GLfloat>::toGLfloatArray(m);
    int j = 0;
    for (int i = m.size() - 1; i != -1 ; --i) {
	_verts[j + 0] = m.at(i).getX();
	_verts[j + 1] = m.at(i).getY();
	_verts[j + 2] = m.at(i).getZ();
	std::cout << "v:" << _verts[j + 0] << _verts[j + 1] <<  _verts[j + 2] << std::endl;
	j += 3;
    }
    _vertexCount = m.size();

    /* VERTEX BUFFER OBJECT SET */
    glGenBuffers(1, &_vboID);
    glBindBuffer(GL_ARRAY_BUFFER, _vboID); // bind (enable) buffer
    // Put data in currently bound buffer
    glBufferData(GL_ARRAY_BUFFER, (_vertexCount) * 3 * sizeof(GLfloat), &_verts[0], GL_STATIC_DRAW);

    /* VERTEX ARRAY OBJECT */
    glGenVertexArrays(1, &_vaoID);
    glBindVertexArray(_vaoID); // make our VAO the current bound VAO
    glEnableVertexAttribArray(0); // add a new variable for position as location 0 to our VAO
    glBindBuffer(GL_ARRAY_BUFFER, _vaoID); // make our VBO the currently bound VBO
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte*)NULL); // map memory for the 0th variable that is the size of 3 floats
    for (int i = 0 ; i <= (_vertexCount * 3 - 1); i += 3) {
        std::cout << "v:"<< (i + 1) / 3 << " X : = " << _verts[i] << std::endl;
        std::cout << "v:"<< (i + 1) / 3 << " Y : = " << _verts[i + 1] << std::endl;
        std::cout << "v:"<< (i + 1) / 3 << " Z : = " << _verts[i + 2] << std::endl << std::endl;
    }
}

void newin::Mesh::setShader(ShadeProgram* s) {
    _s = s;
}

void newin::Mesh::render() {
    // enable shader
    if (_s)
	glUseProgram(_s->getID());
    else
	glUseProgram(0);
    // enable a range of gl rendering options specific to our object
    glEnable(GL_DEPTH_TEST); // enable depth-testing
    glDepthMask(GL_TRUE); // turn back on
    glDepthFunc(GL_LESS);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);
    // bind VAO
    glBindVertexArray(_vaoID);
    // draw
    glDrawArrays(GL_TRIANGLES, 0, _vertexCount); // draw triangles using VBO points from 0 up to vertexCount
    // unbind VAO
    glBindVertexArray(0); // '0' is a reserved index in GL meaning "none"
}

newin::Mesh::~Mesh() {
}
