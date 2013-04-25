#include <iostream>
#include "mesh.hh"

newin::Mesh::Mesh(const std::vector<Vector3D<GLfloat> >& m) {
    _verts = Vector3D<GLfloat>().toGLvector3f(m);
    _vertexCount = _verts->size();

    /* VERTEX BUFFER OBJECT SET */
    glGenBuffers(1, &_vboID);
    glBindBuffer(GL_ARRAY_BUFFER, _vboID); // bind (enable) buffer
    // Put data in currently bound buffer
    glBufferData(GL_ARRAY_BUFFER, _vertexCount * sizeof(GLvector3f), &_verts[0], GL_STATIC_DRAW);

    /* VERTEX ARRAY OBJECT */
    glGenVertexArrays(1, &_vaoID);
    glBindVertexArray(_vaoID); // make our VAO the current bound VAO
    glEnableVertexAttribArray(0); // add a new variable for position as location 0 to our VAO

    glBindBuffer(GL_ARRAY_BUFFER, _vaoID); // make our VBO the currently bound VBO
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte *)NULL); // map memory for the 0th variable that is the size of 3 floats
}

void newin::Mesh::setShader(ShadeProgram* s) {
    _s = s;
}

void newin::Mesh::render() {
    // enable shader
    glUseProgram(_s->getID());
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
